int __fastcall node_has_side_effects(c2_node *n)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  c2_node *dst_node;
  
  switch(*(undefined1 *)((int)node_has_side_effects_jump_table + n->kind + 0x1b)) {
  case 0:
    if (((uint)n[1].next & 0x40) != 0) {
      return 1;
    }
    if (((uint)n[1].next & 0x800) != 0) {
      return 1;
    }
    break;
  case 2:
    if ((g_opt_basic != 0) && (iVar2 = op_has_side_effect_special((c2_tuple *)n), iVar2 != 0)) {
      return 1;
    }
    uVar3 = n->op;
    if (uVar3 == 0x19e) {
      return 1;
    }
    if ((uVar3 != 0) && (uVar3 < 0x144)) {
      return (uint)((g_x86_op_flags[n->op] & 0xc0000000) != 0);
    }
  case 3:
    for (dst_node = (c2_node *)n[1].rank_or_prev; dst_node != (c2_node *)0x0;
        dst_node = dst_node->next) {
      iVar2 = node_has_side_effects(dst_node);
      if (iVar2 != 0) {
        return 1;
      }
    }
    dst_node = *(c2_node **)&n[1].kind;
    if (dst_node != (c2_node *)0x0) {
      while (iVar2 = node_has_side_effects(dst_node), iVar2 == 0) {
        dst_node = dst_node->next;
        if (dst_node == (c2_node *)0x0) {
          return 0;
        }
      }
switchD_107034e6_caseD_4:
      return 1;
    }
    break;
  case 4:
    goto switchD_107034e6_caseD_4;
  case 5:
    uVar1 = *(ushort *)&n[2].next;
    uVar3 = (uint)uVar1;
    if ((g_intrinsic_desc[uVar3].flags & 0x20) == 0) {
      if (0xa2 < uVar1) {
        switch(uVar3) {
        case 0xa5:
        case 0xa7:
        case 0xaa:
        case 0xae:
        case 0xd9:
        case 0xda:
        case 0xde:
        case 0xe5:
        case 0xec:
        case 0xed:
        case 0x153:
        case 0x17f:
        case 0x180:
          goto switchD_107034e6_caseD_1;
        default:
          goto switchD_107034e6_caseD_4;
        }
      }
      if (uVar1 < 0x9f) {
        switch(uVar3) {
        case 3:
        case 5:
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x14:
        case 0x17:
        case 0x1c:
        case 0x21:
        case 0x47:
        case 0x49:
        case 0x4a:
        case 0x4e:
        case 0x4f:
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0x5c:
        case 0x5d:
        case 0x5e:
        case 0x5f:
        case 0x60:
        case 0x61:
        case 0x62:
        case 99:
        case 100:
        case 0x65:
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
        case 0x6c:
        case 0x6d:
        case 0x6e:
        case 0x6f:
        case 0x70:
        case 0x71:
        case 0x72:
        case 0x73:
        case 0x74:
        case 0x75:
        case 0x76:
        case 0x77:
        case 0x78:
        case 0x79:
        case 0x7a:
        case 0x7b:
        case 0x7c:
        case 0x7d:
        case 0x7e:
        case 0x7f:
        case 0x80:
        case 0x81:
        case 0x82:
        case 0x83:
        case 0x84:
        case 0x85:
        case 0x86:
        case 0x87:
        case 0x88:
        case 0x89:
        case 0x8a:
        case 0x8b:
          break;
        default:
          goto switchD_107034e6_caseD_4;
        }
      }
    }
    break;
  case 6:
    if (n->op == 0x1a8) {
      return (uint)(g_opt_eh_enabled == 0);
    }
    goto switchD_107034e6_caseD_4;
  }
switchD_107034e6_caseD_1:
  return 0;
}

