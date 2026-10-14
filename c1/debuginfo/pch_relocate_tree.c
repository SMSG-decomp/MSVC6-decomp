void __cdecl pch_relocate_tree(c1_node *node)

{
  char cVar1;
  
  if (node != (c1_node *)0x0) {
    do {
      pch_relocate_slot_once(&g_pch_image,(uint)&node->type);
      pch_relocate_slot_once(&g_pch_image,(uint)&node->link);
      switch(node->kind & 7) {
      case 1:
        pch_relocate_slot_once(&g_pch_image,(uint)&node->left);
        node = node->left;
        break;
      case 2:
        pch_relocate_slot_once(&g_pch_image,(uint)&node->right);
        cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)&node->left);
        if (cVar1 != '\0') {
          pch_relocate_tree(node->left);
        }
        node = node->right;
        break;
      case 3:
        if (((byte)node->type->code >> 5 & 1) == 0) {
          return;
        }
      case 4:
      case 5:
        pch_relocate_slot_once(&g_pch_image,(uint)&node->left);
      default:
        goto switchD_10644257_default;
      }
      if (node == (c1_node *)0x0) {
        return;
      }
    } while( true );
  }
switchD_10644257_default:
  return;
}

