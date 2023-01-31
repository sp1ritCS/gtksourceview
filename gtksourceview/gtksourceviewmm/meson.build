# gtksourceview/gtksourceviewmm

# Input: gtksourceviewmm_build_dep, gtksourceviewmm_pcname, maintainer_mode, project_source_root,
#        generate_binding, m4_files, gtksourceviewmm_libversion, install_includedir,
#        macos_darwin_versions, python3, can_add_dist_script
# Output: hg_ccg_basenames, extra_h_files, built_h_file_targets, built_files_root,
#         gtksourceviewmm_own_dep

defs_basefiles = [
  'gtksourceview.defs',
  'gtksourceview_signals.defs',
  'gtksourceview_methods.defs',
  'gtksourceview_enums.defs',
  'gtksourceview_others.defs',
  'gtksourceview_vfuncs.defs',
  'gtksourceview_docs.xml',
  'gtksourceview_docs_override.xml'
]

defs_files = []
foreach file : defs_basefiles
  defs_files += '..' / 'src' / file
endforeach

hg_ccg_basenames = [
  'buffer',
  'completion',
  'completionactivation',
  'completioncontext',
  'completioninfo',
  'completionitem',
  'completionproposal',
  'completionprovider',
  'completionwords',
  'gutter',
  'gutterrenderer',
  'gutterrendererpixbuf',
  'gutterrenderertext',
  'language',
  'languagemanager',
  'mark',
  'markattributes',
  'printcompositor',
  'searchcontext',
  'searchsettings',
  'style',
  'stylescheme',
  'styleschememanager',
  'styleschemechooser',
  'styleschemechooserbutton',
  'styleschemechooserwidget',
  'undomanager',
  'view'
]

extra_cc_files = [
  'init.cc',
  'markup.cc'
]

extra_h_files = [
  'wrap_init.h',
  'init.h',
  'markup.h'
]

install_headers('..' / 'gtksourceviewmm.h', subdir: gtksourceviewmm_pcname)
install_headers(extra_h_files, subdir: gtksourceviewmm_pcname / 'gtksourceviewmm')

untracked_gtksourceviewmm = 'untracked' / 'gtksourceview' / 'gtksourceviewmm'
rel_untracked_gtksourceviewmm = '..' / '..' / untracked_gtksourceviewmm
src_untracked_gtksourceviewmm = project_source_root / untracked_gtksourceviewmm

if maintainer_mode

  # Maintainer mode. Generate .h and .cc files from .hg and .ccg files in ../src.

  # doc/reference/meson.build needs this.
  built_files_root = project_build_root
  built_h_file_targets = []

  # Force meson+ninja to generate source files before anything is compiled.
  # Compilation must depend on these targets.
  built_cc_file_targets = []

  hg_files = []
  foreach file : hg_ccg_basenames
    hg_files += '..' / 'src' / file + '.hg'
  endforeach

  # Create wrap_init.cc in project_build_root/gtksourceview/gtksourceviewmm.
  built_cc_file_targets += custom_target('wrap_init.cc',
    input: hg_files,
    output: 'wrap_init.cc',
    command: [
      python3, generate_binding, 'generate_wrap_init',
      gmmproc_dir,
      '@OUTPUT@',
      'Gsv', # namespace
      '@INPUT@',
    ],
    build_by_default: maintainer_mode,
    install: false,
  )

  # Create .h/_p.h/.cc files from .hg/.ccg files in project_build_root/gtksourceview/gtksourceviewmm.
  foreach file : hg_ccg_basenames
    hg_file = '..' / 'src' / file + '.hg'
    ccg_file = '..' / 'src' / file + '.ccg'
    built_file_target = custom_target(file + '.cc',
      input: [hg_file, ccg_file],
      output: [file + '.stamp', file + '.cc', file + '.h'],
      command: [
        python3, generate_binding, 'gmmproc',
        gmmproc_dir,
        '@OUTPUT0@',
        file,
        meson.current_source_dir() / '..' / 'src',
        project_source_root / 'codegen' / 'm4',
        gmmproc_extra_m4_dirs
      ],
      depend_files: defs_files + m4_files,
      build_by_default: maintainer_mode,
      install: false,
    )
    built_cc_file_targets += built_file_target[1]
    built_h_file_targets += built_file_target[2]
  endforeach

  extra_include_dirs = ['..']
  gtksourceviewmm_library = library(gtksourceviewmm_pcname,
    built_cc_file_targets, built_h_file_targets, extra_cc_files,
    version: gtksourceviewmm_libversion,
    darwin_versions: macos_darwin_versions,
    implicit_include_directories: false,
    include_directories: extra_include_dirs,
    dependencies: gtksourceviewmm_build_dep,
    install: true,
  )

  built_h_cc_dir = meson.current_build_dir()

else # not maintainer_mode

  # Not maintainer mode. Compile built source code files in
  # project_source_root/untracked/gtksourceview/gtksourceviewmm.

  # doc/reference/meson.build needs these.
  built_files_root = project_source_root / 'untracked'
  built_h_file_targets = []

  # Two cases:
  # 1. The source code comes from a tarball, where the built files
  #    are stored in project_source_root/untracked.
  #    There are no built files in the build tree.
  # 2. Files have been built in the build tree. Then maintainer_mode has
  #    been changed from true to false. Files that are missing or not up to date
  #    in project_source_root/untracked are copied from the build tree.

  # Try to copy built source code files to the source tree.
  run_command(
    python3, generate_binding, 'copy_built_files',
    meson.current_build_dir(),
    src_untracked_gtksourceviewmm,
    hg_ccg_basenames,
    check: true,
  )

  built_cc_files = [ rel_untracked_gtksourceviewmm / 'wrap_init.cc' ]
  foreach file : hg_ccg_basenames
    built_cc_files += rel_untracked_gtksourceviewmm / file + '.cc'
  endforeach

  extra_include_dirs = [ '..', '..' / '..' / 'untracked' / 'gtksourceview' ]
  gtksourceviewmm_library = library(gtksourceviewmm_pcname,
    built_cc_files, extra_cc_files,
    version: gtksourceviewmm_libversion,
    darwin_versions: macos_darwin_versions,
    implicit_include_directories: false,
    include_directories: extra_include_dirs,
    dependencies: gtksourceviewmm_build_dep,
    install: true,
  )

  built_h_cc_dir = src_untracked_gtksourceviewmm

endif

# Install built .h and _p.h files.
meson.add_install_script(
  python3, generate_binding, 'install_built_h_files',
  built_h_cc_dir,
  install_includedir / gtksourceviewmm_pcname / 'gtksourceviewmm', # subdir below {prefix}
  hg_ccg_basenames
)

if can_add_dist_script
  # Distribute built files.
  meson.add_dist_script(
    python3, generate_binding, 'dist_built_files',
    built_h_cc_dir,
    untracked_gtksourceviewmm,
    hg_ccg_basenames,
  )
endif

# This is used when building example programs and test programs.
# It's also a part of gtksourceviewmm_dep, when gtksourceviewmm is a subproject.
gtksourceviewmm_own_dep = declare_dependency(
  sources: built_h_file_targets,
  link_with: gtksourceviewmm_library,
  include_directories: extra_include_dirs,
  dependencies: gtksourceviewmm_build_dep
)
