char * __cdecl misc_string_get(int id)

{
  char *pcVar1;
  
  if (g_misc_strings_loaded == '\0') {
    misc_strings_load();
    g_misc_strings_loaded = '\x01';
  }
  pcVar1 = misc_string_find(id);
  return pcVar1;
}

