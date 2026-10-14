c1_node * __fastcall expr_new_build_call_node(void *call)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_type *type;
  
  if ((*(byte *)((int)call + 0x24) & 1) == 0) {
    pcVar2 = tree_new_symbol_ref(*(c1_symbol **)((int)call + 0x10),'\x01');
    *(c1_node **)((int)call + 8) = pcVar2;
  }
  pcVar2 = *(c1_node **)((int)call + 8);
  if ((*(byte *)((int)call + 0x24) & 2) != 0) {
    pcVar2 = tree_new_binary(0x99,pcVar2,*(c1_node **)((int)call + 0x14));
    *(c1_node **)((int)call + 0xc) = pcVar2;
  }
  pcVar1 = *(c1_node **)((int)call + 0x18);
  if ((pcVar1 != (c1_node *)0x0) && (pcVar1->op == '7')) {
    *(void **)((int)call + 0x18) = pcVar1->left;
    pcVar1->left = pcVar1->right;
    pcVar1->right = pcVar2;
    pcVar1->type = pcVar2->type;
    pcVar2 = pcVar1;
  }
  type = type_function_return(pcVar2->type);
  pcVar2 = tree_new_node('p',pcVar2,*(c1_node **)((int)call + 0x18),type);
  *(c1_node **)call = pcVar2;
  *(c1_node **)((int)call + 4) = pcVar2;
  return pcVar2;
}

