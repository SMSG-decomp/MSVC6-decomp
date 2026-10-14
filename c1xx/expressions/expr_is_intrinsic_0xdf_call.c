int __cdecl expr_is_intrinsic_0xdf_call(char *node)

{
  char *pcVar1;
  
  if (node == (char *)0x0) {
    return 0;
  }
  if ((((*node == 'w') && (pcVar1 = *(char **)(node + 0x10), *pcVar1 == 'e')) &&
      (*(int *)(pcVar1 + 0x10) == 0xdf)) && (*(int *)(pcVar1 + 0x14) == 0)) {
    return 1;
  }
  return 0;
}

