c1_node * __cdecl decl_chain_default_arguments(c1_arg_list *args)

{
  c1_arg_item *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  
  pcVar4 = (c1_node *)0x0;
  if (args != (c1_arg_list *)0x0) {
    pcVar1 = args->first;
    if ((pcVar1->kind & 3) != 1) {
      return (c1_node *)0x0;
    }
    pcVar4 = (pcVar1->value).expr;
    pcVar3 = pcVar4;
    for (pcVar1 = pcVar1->next; (pcVar1 != (c1_arg_item *)0x0 && ((pcVar1->kind & 3) == 1));
        pcVar1 = pcVar1->next) {
      pcVar2 = (pcVar1->value).expr;
      pcVar3->right = pcVar2;
      pcVar2->link = pcVar3;
      pcVar3 = pcVar3->right;
    }
    pcVar4->link = pcVar3;
  }
  return pcVar4;
}

