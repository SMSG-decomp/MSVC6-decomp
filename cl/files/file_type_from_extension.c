int __cdecl file_type_from_extension(char *path)

{
  int diff;
  int type;
  int *kind;
  char ext [256];
  
  type = 0;
  _splitpath(path,(char *)0x0,(char *)0x0,(char *)0x0,ext);
  if (ext[0] != '\0') {
    kind = &g_file_types[0].kind;
    do {
      diff = _stricmp(ext + 1,(char *)kind[-1]);
      if (diff == 0) {
        return type;
      }
      kind = kind + 3;
      type = type + 1;
    } while (*kind != 2);
  }
  return 8;
}

