c1_node * __cdecl tree_strip_casts_and_segment_bases(c1_node *node)

{
  byte *pbVar1;
  c1_node *pcVar2;
  int iVar3;
  
  do {
    while( true ) {
      while (pcVar2 = node, pcVar2->op == 'd') {
        node = pcVar2->left;
      }
      if (pcVar2->op != ']') {
        return pcVar2;
      }
      pbVar1 = pcVar2->right;
      if (pbVar1 != (byte *)0x0) break;
      node = pcVar2->left;
    }
    node = pcVar2->left;
    if ((*(byte *)(((uint)node->type & -(uint)((node->type->code & 0x80) != 0)) + 2) & 0x18) != 0x18
       ) {
      return pcVar2;
    }
    if (g_token_class[*pbVar1] == '=') {
      iVar3 = *(int *)(*(int *)(pbVar1 + 0x10) + 0x10);
    }
    else {
      iVar3 = *(int *)(pbVar1 + 0x10);
    }
  } while ((-1 < **(char **)(iVar3 + 0x14)) || (*(char **)(iVar3 + 0x14) == (char *)0x0));
  return pcVar2;
}

