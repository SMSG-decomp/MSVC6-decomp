void __cdecl import_write_named_guid(void *guid,char *prefix,wchar_t *name)

{
  if (g_import_named_guids != 0) {
    import_text_printf(g_import_named_guid_inits,
                       "extern \"C\" const GUID __declspec(selectany) %sID_%S =\n    ",prefix,name);
    import_write_guid_initializer(g_import_named_guid_inits,guid);
    import_text_puts(g_import_named_guid_inits,";\n");
  }
  return;
}

