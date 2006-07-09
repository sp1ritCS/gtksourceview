// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtksourceviewmm/sourcetagtable.h>
#include <gtksourceviewmm/private/sourcetagtable_p.h>


namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<gtksourceview::SourceTagTable> wrap(GtkSourceTagTable* object, bool take_copy)
{
  return Glib::RefPtr<gtksourceview::SourceTagTable>( dynamic_cast<gtksourceview::SourceTagTable*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace gtksourceview
{


/* The *_Class implementation: */

const Glib::Class& SourceTagTable_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SourceTagTable_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_source_tag_table_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void SourceTagTable_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


Glib::ObjectBase* SourceTagTable_Class::wrap_new(GObject* object)
{
  return new SourceTagTable((GtkSourceTagTable*)object);
}


/* The implementation: */

GtkSourceTagTable* SourceTagTable::gobj_copy()
{
  reference();
  return gobj();
}

SourceTagTable::SourceTagTable(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{}

SourceTagTable::SourceTagTable(GtkSourceTagTable* castitem)
:
  Glib::Object((GObject*)(castitem))
{}

SourceTagTable::~SourceTagTable()
{}


SourceTagTable::CppClassType SourceTagTable::sourcetagtable_class_; // initialize static member

GType SourceTagTable::get_type()
{
  return sourcetagtable_class_.init().get_type();
}

GType SourceTagTable::get_base_type()
{
  return gtk_source_tag_table_get_type();
}


SourceTagTable::SourceTagTable()
:
  Glib::ObjectBase(0), //Mark this class as gtkmmproc-generated, rather than a custom class, to allow vfunc optimisations.
  Glib::Object(Glib::ConstructParams(sourcetagtable_class_.init()))
{
  }

Glib::RefPtr<SourceTagTable> SourceTagTable::create()
{
  return Glib::RefPtr<SourceTagTable>( new SourceTagTable() );
}
void SourceTagTable::add_tags(const Glib::SListHandle<Glib::RefPtr<Gtk::TextTag> > & a_tags)
{
gtk_source_tag_table_add_tags(gobj(), a_tags.data()); 
}

void SourceTagTable::remove_source_tags()
{
gtk_source_tag_table_remove_source_tags(gobj()); 
}


#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace gtksourceview


