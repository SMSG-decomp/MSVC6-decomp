void __fastcall expr_call_info_decode_callee(c1_call_record *info)

{
  byte bVar1;
  c1_node *pcVar2;
  
  pcVar2 = info->call->left;
  if (pcVar2->op == '7') {
    pcVar2 = pcVar2->right;
  }
  if (pcVar2->op == 0x99) {
    info->this_arg = pcVar2;
    info->flags = info->flags | 2;
    info->object = pcVar2->right;
    pcVar2 = pcVar2->left;
  }
  info->callee = pcVar2;
  if (pcVar2->op == '\x06') {
    info->function = pcVar2->left;
    info->flags = info->flags | 4;
    return;
  }
  bVar1 = info->flags;
  info->flags = bVar1 | 1;
  info->flags = bVar1 | 5;
  return;
}

