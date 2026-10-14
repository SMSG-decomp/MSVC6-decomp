char * __cdecl expr_string_literal_lookup_name(char **text,char wide)

{
  char *pcVar1;
  
  g_decorated_name_start = g_decorated_name;
  pcVar1 = decorate_string_literal_name_body
                     (g_decorated_name,(ushort *)*text,(uint)*(ushort *)(text + 1),wide);
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
    return g_decorated_name;
  }
  return (char *)0x0;
}

