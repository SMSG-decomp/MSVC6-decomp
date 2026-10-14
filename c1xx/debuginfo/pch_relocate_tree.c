void __cdecl pch_relocate_tree(c1_node *node)

{
  char cVar1;
  void **slot;
  void **list;
  
  if (node != (c1_node *)0x0) {
    do {
      pch_relocate_slot_once(&g_pch_image,(uint *)&node->type);
      pch_relocate_slot_once(&g_pch_image,(uint *)&node->link);
      switch(node->kind & 7) {
      case 0:
        if (node->op != 0xc6) {
          if (node->op != 0x98) {
            return;
          }
          pch_relocate_slot_once(&g_pch_image,(uint *)&node->left);
          return;
        }
        cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&node->left);
        if (cVar1 == '\0') {
          return;
        }
        token_io_release_record((int)node->left);
        return;
      case 1:
        pch_relocate_slot_once(&g_pch_image,(uint *)&node->left);
        node = node->left;
        goto LAB_1048b392;
      case 2:
        slot = &node->right;
        pch_relocate_slot_once(&g_pch_image,(uint *)slot);
        cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&node->left);
        if (cVar1 != '\0') {
          pch_relocate_tree(node->left);
        }
        break;
      case 3:
        if (((byte)node->type->code >> 5 & 1) == 0) {
          return;
        }
        pch_relocate_slot_once(&g_pch_image,(uint *)&node->left);
        return;
      case 4:
        if (node->op == 0x9c) {
          return;
        }
      case 5:
        pch_relocate_slot_once(&g_pch_image,(uint *)&node->left);
        return;
      default:
        goto switchD_1048b37b_caseD_6;
      case 7:
        switch(node->op) {
        case 0xb5:
        case 0xb6:
          slot = &node->left;
          pch_relocate_slot_once(&g_pch_image,(uint *)slot);
          cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&node->right);
          if (cVar1 != '\0') {
            list = node->right;
LAB_1048b40c:
            slot = &node->left;
            pch_relocate_tree_list_list(list);
          }
          break;
        case 0xb7:
          slot = &node->left;
          pch_relocate_slot_once(&g_pch_image,(uint *)slot);
          cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&node->right);
          if (cVar1 != '\0') {
            list = node->right;
            goto LAB_1048b40c;
          }
          break;
        default:
          goto switchD_1048b37b_caseD_6;
        case 0xc5:
          slot = &node->left;
          pch_relocate_slot_once(&g_pch_image,(uint *)slot);
          cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&node->right);
          if (cVar1 != '\0') {
            pch_relocate_tree_list(node->right);
          }
        }
      }
      node = *slot;
LAB_1048b392:
      if (node == (c1_node *)0x0) {
        return;
      }
    } while( true );
  }
switchD_1048b37b_caseD_6:
  return;
}

