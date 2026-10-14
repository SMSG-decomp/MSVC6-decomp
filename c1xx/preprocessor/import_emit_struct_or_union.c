void __cdecl
import_emit_struct_or_union(char *keyword,void *typeinfo,c1_typeattr *typeattr,wchar_t *name)

{
  if (typeattr->cVars != 0) {
    import_text_printf(g_import_items,"\n%s %S\n{\n",keyword,name);
    import_emit_record_fields(typeinfo,typeattr,(wchar_t *)0x0);
    import_text_puts(g_import_items,"};\n");
  }
  return;
}

