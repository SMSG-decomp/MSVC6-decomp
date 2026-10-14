int __cdecl expr_call_argument_size(c1_node *node)

{
  void *pvVar1;
  c1_type *type;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (node != (c1_node *)0x0) {
    for (pvVar1 = node->right; pvVar1 != (void *)0x0; pvVar1 = *(void **)((int)pvVar1 + 0x14)) {
      type = *(c1_type **)((int)pvVar1 + 4);
      if (type == g_type_none) {
        type = *(c1_type **)(*(int *)((int)pvVar1 + 0x10) + 4);
      }
      iVar2 = type_argument_size(type,'\x01');
      iVar3 = iVar3 + (iVar2 + 3U & 0xfffffffc);
    }
    return iVar3;
  }
  return 0;
}

