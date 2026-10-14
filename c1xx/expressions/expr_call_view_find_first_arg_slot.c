void __fastcall expr_call_view_find_first_arg_slot(c1_call_record *view)

{
  c1_node *pcVar1;
  byte bVar2;
  
  if ((view->flags & 4) == 0) {
    expr_call_info_decode_callee(view);
  }
  if ((view->function->flags1 & 0x10) == 0x10) {
    bVar2 = view->flags & 0xef;
    view->flags = bVar2;
    view->arg_slot = view->object;
    view->arg_expr = view->object->left;
    view->flags = bVar2 | 8;
    return;
  }
  view->flags = view->flags | 0x10;
  pcVar1 = *(c1_node **)((int)view->call->right + 8);
  view->arg_slot = pcVar1;
  view->arg_expr = pcVar1->left;
  view->flags = view->flags | 8;
  return;
}

