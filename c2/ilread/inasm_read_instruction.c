c2_tuple * __fastcall inasm_read_instruction(uint8_t *insn,c2_scope_table *scope)

{
  byte bVar1;
  byte bVar2;
  c2_fe_symbol *label_sym;
  bool bVar3;
  uint8_t *puVar4;
  c2_symbol *pcVar5;
  c2_tuple *pcVar6;
  c2_operand *pcVar7;
  c2_operand *dst;
  ushort uVar8;
  uint size;
  ushort type;
  byte *pbVar9;
  uint32_t op;
  uint32_t op_00;
  c2_insert_fn *insert_fn;
  uint32_t size_00;
  int local_28;
  c2_operand **local_24;
  int local_1c;
  c2_operand *local_c;
  c2_operand *local_8;
  c2_operand *local_4;
  
  local_4 = (c2_operand *)0x0;
  local_c = (c2_operand *)0x0;
  local_8 = (c2_operand *)0x0;
  bVar1 = *insn;
  op = (uint32_t)insn[1];
  pbVar9 = insn + 2;
  bVar3 = false;
  type = 0;
  if (g_inasm_wide_opcodes != 0) {
    op = (uint32_t)CONCAT11(*pbVar9,insn[1]);
    pbVar9 = insn + 3;
  }
  if (0x10b < op) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x41);
  }
  if ((op == 0) || (0x143 < op)) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x42);
  }
  local_28 = (int)g_x86_op_operand_count[op];
  bVar2 = *pbVar9;
  size = (uint)bVar2;
  pbVar9 = pbVar9 + 1;
  switch(op) {
  case 8:
    size_00 = 4;
    op_00 = op;
    goto LAB_10772e9b;
  default:
    goto switchD_10772dc5_caseD_9;
  case 10:
    puVar4 = inasm_read_operand(&local_8,pbVar9,scope,op,2);
    pbVar9 = inasm_read_operand(&local_c,puVar4,scope,op,size);
    break;
  case 0xb:
    puVar4 = inasm_read_operand(&local_c,pbVar9,scope,op,2);
    pbVar9 = inasm_read_operand(&local_8,puVar4,scope,op,size);
    break;
  case 0x1e:
  case 0x21:
    local_28 = 2;
    goto switchD_10772dc5_caseD_9;
  case 0x23:
  case 0x24:
  case 0x5f:
    bVar3 = true;
    goto switchD_10772dc5_caseD_9;
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0xc2:
  case 0xc4:
    puVar4 = inasm_read_operand(&local_c,pbVar9,scope,op,size);
    pbVar9 = inasm_read_operand(&local_8,puVar4,scope,op,1);
    break;
  case 0x56:
    local_c = operand_new_hardreg(0x1f,0x4008);
    pbVar9 = inasm_read_operand(&local_8,pbVar9,scope,op,size);
    size = 8;
    local_28 = 2;
    break;
  case 0x5a:
  case 0x5b:
    type = bVar2 | 0x1000;
    pbVar9 = inasm_read_operand(&local_c,pbVar9,scope,op,size);
    local_c->type = type;
    local_8 = operand_new_hardreg(0x1f,0x4008);
    local_28 = 2;
    break;
  case 0x60:
    pbVar9 = inasm_read_operand(&local_8,pbVar9,scope,op,size);
    local_c = operand_new_hardreg(0x1f,bVar2 | 0x4000);
    local_28 = 2;
    break;
  case 0x62:
  case 99:
    pbVar9 = inasm_read_operand(&local_c,pbVar9,scope,op,size);
    uVar8 = (ushort)bVar2;
    if (7 < bVar2) {
      uVar8 = 8;
    }
    local_8 = operand_new_hardreg(0x1f,uVar8 | 0x4000);
    local_28 = 2;
    break;
  case 0x6c:
  case 0x6e:
    size_00 = 2;
    op_00 = 1;
LAB_10772e9b:
    pbVar9 = inasm_read_operand(&local_c,pbVar9,scope,op_00,size_00);
    break;
  case 0x99:
    if (size == 1) {
      size = 2;
    }
    else {
      if (size != 2) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x60);
      }
      op = 0xde;
LAB_10772de6:
      size = 4;
    }
    break;
  case 0x9f:
    if (size == 2) goto LAB_10772de6;
    if (size != 4) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x6e);
    }
    size = 8;
    op = 0xdf;
    break;
  case 0xa3:
    local_28 = 3;
    goto switchD_10772dc5_caseD_9;
  case 0xb4:
    op = 0xbb;
    goto switchD_10772dc5_caseD_9;
  case 0xbd:
    op = size + 0x11c;
    size = 1;
    goto switchD_10772dc5_caseD_9;
  case 0xc3:
  case 0xc5:
    puVar4 = inasm_read_operand(&local_c,pbVar9,scope,op,size);
    pbVar9 = inasm_read_operand(&local_8,puVar4,scope,op,2);
    break;
  case 0xca:
  case 0xcb:
    puVar4 = inasm_read_operand(&local_c,pbVar9,scope,op,size);
    pbVar9 = inasm_read_operand(&local_8,puVar4,scope,op,size);
    if (local_8->kind == '\x01') {
      local_4 = operand_new_hardreg(0x12,0x2001);
      local_28 = 3;
    }
    else {
      local_4 = operand_new_intconst(0x2001,local_8->disp,local_8->disp >> 0x1f);
      pcVar5 = reg_find_subreg((local_8->base->u18).reg,size * 8,0);
      pcVar7 = operand_new_hardreg(pcVar5->id,bVar2 | 0x1000);
      node_free((c2_node *)local_8);
      local_28 = 3;
      local_8 = pcVar7;
    }
    break;
  case 0x104:
    op = size + 300;
    size = 4;
    goto switchD_10772dc5_caseD_9;
  case 0x105:
    op = size + 300;
    size = 2;
switchD_10772dc5_caseD_9:
    if (0 < local_28) {
      local_24 = &local_c;
      local_1c = local_28;
      do {
        pbVar9 = inasm_read_operand(local_24,pbVar9,scope,op,size);
        local_24 = local_24 + 1;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
    }
    break;
  case 0x106:
    switch(size) {
    case 2:
      op = 0x13c;
      break;
    case 3:
      op = 0x140;
      break;
    case 4:
      op = 0x13d;
      break;
    case 5:
      op = 0x141;
      break;
    case 6:
      op = 0x13e;
      break;
    case 7:
      op = 0x142;
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x111);
    case 10:
      op = 0x13f;
      break;
    case 0xb:
      op = 0x143;
    }
    size = 8;
    pbVar9 = inasm_read_operand(&local_c,pbVar9,scope,op,8);
    local_8 = operand_new_hardreg(0x1f,0x4008);
    local_4 = operand_new_hardreg(0x4a,0x8000);
    local_28 = 3;
  }
  if ((int)pbVar9 - (int)insn != (uint)bVar1) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x1c8);
  }
  switch(op) {
  case 8:
    if (size == 6) {
      op = 0x117;
    }
    pcVar6 = tuple_new_exit(op,0x1004,(c2_operand *)0x0,local_c,(c2_insert_fn *)0x0,(c2_tuple *)0x0)
    ;
    goto LAB_10773109;
  default:
    uVar8 = (ushort)size;
    if (type == 0) {
      if (((g_x86_op_flags[op] & 1) == 0) || (size < 4)) {
        if (((g_x86_op_flags[op] & 0x2000) == 0) || (size < 8)) {
          type = uVar8 | 0x1000;
        }
        else {
          type = uVar8 | 0xa000;
        }
      }
      else {
        type = uVar8 | 0x4000;
      }
    }
    if ((g_x86_op_flags[op] & 0x800) == 0) {
      if ((1 < local_28) || (bVar3)) {
        if (op < 0x54) {
          if (op < 0x52) {
            switch(op) {
            case 3:
            case 4:
            case 0xb:
            case 0x2f:
            case 0x33:
              goto switchD_107733cc_caseD_3;
            default:
              goto switchD_107733cc_caseD_5;
            }
          }
switchD_107733e5_caseD_5c:
          pcVar7 = operand_new_hardreg(0x4a,0x8000);
        }
        else {
          switch(op) {
          case 0x5c:
          case 0x5d:
          case 0xd1:
          case 0xd2:
            goto switchD_107733e5_caseD_5c;
          default:
switchD_107733cc_caseD_5:
            pcVar7 = (c2_operand *)node_clone((c2_node *)local_c);
            break;
          case 0xcc:
switchD_107733cc_caseD_3:
            pcVar7 = operand_new_hardreg(0x42,0x8000);
            break;
          case 0x13c:
          case 0x13d:
          case 0x13e:
          case 0x13f:
          case 0x140:
          case 0x141:
          case 0x142:
          case 0x143:
            pcVar7 = operand_new_hardreg(0x1f,uVar8 | 0x4000);
          }
        }
        if (local_8 == (c2_operand *)0x0) {
          pcVar6 = tuple_new(op,type,pcVar7,local_c,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
        }
        else {
          pcVar6 = tuple_new_binary(op,type,pcVar7,local_c,local_8,(c2_insert_fn *)0x0,
                                    (c2_tuple *)0x0);
        }
        if (local_4 != (c2_operand *)0x0) {
          pcVar7 = pcVar6->src->next;
          local_4->next = pcVar7->next;
          pcVar7->next = local_4;
        }
      }
      else {
        if (local_c == (c2_operand *)0x0) {
          local_c = inasm_operand_new_result(op,type);
        }
        pcVar6 = (c2_tuple *)0x0;
        insert_fn = (c2_insert_fn *)0x0;
        pcVar7 = local_c;
        dst = inasm_operand_new_result(op,type);
        pcVar6 = tuple_new(op,type,dst,pcVar7,insert_fn,pcVar6);
      }
    }
    else if (local_4 == (c2_operand *)0x0) {
      if (local_8 == (c2_operand *)0x0) {
        local_8 = inasm_operand_new_result(op,type);
      }
      pcVar6 = tuple_new(op,type,local_c,local_8,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    }
    else {
      pcVar6 = tuple_new_binary(op,type,local_c,local_8,local_4,(c2_insert_fn *)0x0,(c2_tuple *)0x0)
      ;
    }
    if ((op == 9) || (op == 0xd9)) {
      pcVar7 = (c2_operand *)node_clone((c2_node *)pcVar6->src->next);
      tuple_append_dst(pcVar6,pcVar7);
    }
    goto LAB_10773109;
  case 0xe:
    if (size == 6) {
      op = 0x116;
    }
    pcVar6 = tuple_new_call(op,0x1004,(c2_operand *)0x0,local_c,'\0',(c2_insert_fn *)0x0,
                            (c2_tuple *)0x0);
    goto LAB_10773109;
  case 0xf:
  case 0x17:
  case 0x18:
  case 0x19:
    break;
  case 0x10:
    if (size == 1) {
      op = 0x115;
    }
    else if (size == 6) {
      op = 0x114;
    }
    break;
  case 0x16:
    if (size == 4) {
      op = 0x11b;
    }
  }
  pcVar7 = local_c;
  if ((local_c->kind == '\x04') &&
     (label_sym = (c2_fe_symbol *)local_c->sym, label_sym->cls == '\x03')) {
    pcVar7 = (c2_operand *)(label_sym->u32).label_tuple;
    if (pcVar7 == (c2_operand *)0x0) {
      pcVar7 = (c2_operand *)tuple_new_label(label_sym);
    }
    node_free((c2_node *)local_c);
  }
  pcVar6 = tuple_new_branch(op,(op != 0xf) - 1U & (byte)size,(c2_node *)pcVar7,(c2_operand *)0x0,
                            (c2_tuple *)0x0,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
LAB_10773109:
  if ((g_x86_op_flags[pcVar6->op] & 1) != 0) {
    switch(pcVar6->op) {
    case 0x49:
    case 0x4a:
    case 0x4f:
    case 0x50:
    case 0x54:
    case 0x55:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0xd4:
      warning(4,0x2d5);
    }
  }
  return pcVar6;
}

