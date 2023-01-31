# gtksourceview

# Input: install_prefix, install_datadir, install_includedir,
#        gtksourceviewmm_pcname, gtksourceviewmm_api_version, gtksourceviewmm_requires,
#        install_pkgconfigdir, install_libdir, build_deprecated_api,
#        gtksourceviewmm_major_version, gtksourceviewmm_minor_version, gtksourceviewmm_micro_version
# Output: pkg_conf_data, install_includeconfigdir

pkg_conf_data = configuration_data()
pkg_conf_data.set('prefix', install_prefix)
pkg_conf_data.set('exec_prefix', '${prefix}')
pkg_conf_data.set('libdir', '${exec_prefix}' / install_libdir)
pkg_conf_data.set('datarootdir', '${prefix}' / install_datadir)
pkg_conf_data.set('datadir', '${datarootdir}')
pkg_conf_data.set('includedir', '${prefix}' / install_includedir)
pkg_conf_data.set('srcdir', meson.current_source_dir())
pkg_conf_data.set('PACKAGE_TARNAME', meson.project_name())
pkg_conf_data.set('PACKAGE_VERSION', meson.project_version())
pkg_conf_data.set('GTKSOURCEVIEWMM_MODULE_NAME', gtksourceviewmm_pcname)
pkg_conf_data.set('GTKSOURCEVIEWMM_API_VERSION', gtksourceviewmm_api_version)
pkg_conf_data.set('GTKSOURCEVIEWMM_MODULES', gtksourceviewmm_requires)

if not build_deprecated_api
  pkg_conf_data.set('GTKSOURCEVIEWMM_DISABLE_DEPRECATED', true)
endif
pkg_conf_data.set('GTKSOURCEVIEWMM_MAJOR_VERSION', gtksourceviewmm_major_version)
pkg_conf_data.set('GTKSOURCEVIEWMM_MINOR_VERSION', gtksourceviewmm_minor_version)
pkg_conf_data.set('GTKSOURCEVIEWMM_MICRO_VERSION', gtksourceviewmm_micro_version)

configure_file(
  input: 'gtksourceviewmm.pc.in',
  output: gtksourceviewmm_pcname + '.pc',
  configuration: pkg_conf_data,
  install_dir: install_pkgconfigdir,
)

configure_file(
  input: 'gtksourceviewmm-uninstalled.pc.in',
  output: gtksourceviewmm_pcname + '-uninstalled.pc',
  configuration: pkg_conf_data,
)

install_includeconfigdir = install_libdir / gtksourceviewmm_pcname / 'include'
configure_file(
  input: 'gtksourceviewmmconfig.h.in',
  output: '@BASENAME@',
  configuration: pkg_conf_data,
  install_dir: install_includeconfigdir,
)

subdir('gtksourceviewmm')
