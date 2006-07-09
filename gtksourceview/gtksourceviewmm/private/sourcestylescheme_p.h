// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCESTYLESCHEME_P_H
#define _GTKSOURCEVIEWMM_SOURCESTYLESCHEME_P_H


#include <glibmm/private/interface_p.h>
#include <gtksourceviewmm/private/sourcetagstyle_p.h>

#include <glibmm/private/interface_p.h>

namespace gtksourceview
{

class SourceStyleScheme_Class : public Glib::Interface_Class
{
public:
  typedef SourceStyleScheme CppObjectType;
  typedef GtkSourceStyleScheme BaseObjectType;
  typedef GTypeInterface BaseClassType;
  typedef Glib::Interface_Class CppClassParent;

  friend class SourceStyleScheme;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED
};


} // namespace gtksourceview


#endif /* _GTKSOURCEVIEWMM_SOURCESTYLESCHEME_P_H */

