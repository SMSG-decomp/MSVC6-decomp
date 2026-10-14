void __thiscall expr_save_operand_for_reuse(c1_call_record *view,c1_node *args)

{
  c1_u8 cVar1;
  c1_node *pcVar2;
  int iVar3;
  c1_node **ppcVar4;
  c1_call_record copy_view;
  
  view->args = view->call->right;
  view->call->right = (void *)0x0;
  pcVar2 = tree_copy_to_arena(view->expr,g_expr_arena_index);
  ppcVar4 = &copy_view.call;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppcVar4 = (c1_node *)0x0;
    ppcVar4 = ppcVar4 + 1;
  }
  if (pcVar2 != (c1_node *)0x0) {
    cVar1 = pcVar2->op;
    copy_view.call = pcVar2;
    while (cVar1 != 'p') {
      copy_view.call = (copy_view.call)->left;
      cVar1 = (copy_view.call)->op;
    }
  }
  view->call->right = view->args;
  if (pcVar2 != (c1_node *)0x0) {
    if (args->op == '7') {
      *(void **)((int)(copy_view.call)->left + 0x10) = args->right;
      args = args->left;
    }
    (copy_view.call)->right = args;
  }
  return;
}

