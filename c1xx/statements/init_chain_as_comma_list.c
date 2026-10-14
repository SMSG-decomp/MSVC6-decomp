c1_node * __cdecl init_chain_as_comma_list(c1_node *list)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  void *pvVar4;
  c1_node *pcVar5;
  
  if (list->right != (void *)0x0) {
    pcVar1 = list->link;
    list->link = (c1_node *)0x0;
    pcVar1->op = '7';
    pcVar2 = pcVar1->link->link;
    pcVar5 = pcVar1;
    while (pcVar2 != (c1_node *)0x0) {
      pcVar3 = pcVar5->link;
      pcVar5->right = pcVar3;
      pcVar3->op = '7';
      pcVar5 = pcVar3;
      pcVar2 = pcVar3->link->link;
    }
    pvVar4 = pcVar5->link->left;
    pcVar5->right = pvVar4;
    pcVar5->type = *(c1_type **)((int)pvVar4 + 4);
    return pcVar1;
  }
  return list->left;
}

