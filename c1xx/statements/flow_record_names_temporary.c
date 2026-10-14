int __cdecl flow_record_names_temporary(char *node,int temp)

{
  if (g_sizeof_depth == 0) {
    if (((node[1] & 7U) == 1) && (*node == 'd')) {
      node = *(char **)(node + 0x10);
    }
    return (uint)(*(int *)(node + 0x10) == temp);
  }
  return 0;
}

