char * __cdecl access_specifier_name(char access)

{
  char *pcVar1;
  
  switch(access) {
  case '\0':
    pcVar1 = misc_string_get(0x150);
    return pcVar1;
  case '\x01':
    return "private";
  case '\x02':
    return "protected";
  case '\x03':
    return "public";
  default:
    return (char *)0x0;
  }
}

