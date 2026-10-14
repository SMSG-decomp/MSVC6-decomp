char * __cdecl tree_find_template_parameter_use(char *node)

{
  byte bVar1;
  char *pcVar2;
  
  while( true ) {
    while( true ) {
      if (node == (char *)0x0) {
        return (char *)0x0;
      }
      if ((node[2] & 8U) != 0) {
        return node;
      }
      bVar1 = node[1] & 7;
      if (bVar1 != 1) break;
      node = *(char **)(node + 0x10);
    }
    if (bVar1 != 2) break;
    pcVar2 = tree_find_template_parameter_use(*(char **)(node + 0x10));
    if (pcVar2 != (char *)0x0) {
      return pcVar2;
    }
    node = *(char **)(node + 0x14);
  }
  if (bVar1 != 4) {
    return (char *)0x0;
  }
  if (*node == -100) {
    return (char *)0x0;
  }
  if ((**(byte **)(node + 0x10) & 0x1f) != 0x17) {
    return (char *)0x0;
  }
  pcVar2 = tree_find_template_parameter_use(*(char **)(*(byte **)(node + 0x10) + 0x2c));
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  return node;
}

