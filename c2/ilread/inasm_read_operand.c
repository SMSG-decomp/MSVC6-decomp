uint8_t * __fastcall
inasm_read_operand(c2_operand **out,uint8_t *p,c2_scope_table *scope,uint32_t op,uint32_t size)

{
  char *pcVar1;
  int32_t *piVar2;
  char cVar3;
  uint8_t uVar4;
  uint32_t *puVar5;
  uint32_t uVar6;
  int iVar7;
  c2_operand *pcVar8;
  c2_symbol *pcVar9;
  c2_fe_symbol *pcVar10;
  c2_const_operand *pcVar11;
  uint16_t type;
  uint16_t type_00;
  uint uVar12;
  uint32_t uVar13;
  char *pcVar14;
  uint uVar15;
  uint uVar16;
  c2_operand *pcVar17;
  uint32_t uVar18;
  uint32_t *local_30;
  c2_symbol *local_2c;
  uint local_28;
  c2_fe_symbol *local_24;
  uint local_20;
  uint32_t local_1c;
  int local_18;
  uint local_14;
  int local_10;
  c2_fe_symbol *local_c;
  int local_8;
  c2_operand **local_4;
  
  uVar12 = (uint)*p;
  uVar16 = 0;
  uVar13 = 0;
  local_30 = (uint32_t *)(p + 1);
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_8 = 1;
  local_1c = 0;
  local_24 = (c2_fe_symbol *)0x0;
  local_2c = (c2_symbol *)0x0;
  local_4 = out;
  if (uVar12 == 0x12) {
    local_10 = 1;
    uVar6 = inasm_read_compact_value((uint16_t **)&local_30);
    local_c = fe_scope_lookup_id(scope,uVar6);
    uVar12 = (uint)*(byte *)((int)local_30 + 1);
    local_14 = (int)(char)*local_30 + 1;
    local_30 = (uint32_t *)((int)local_30 + 2);
  }
  else {
    local_10 = 0;
    local_c = (c2_fe_symbol *)0x0;
    local_14 = 0;
  }
  pcVar14 = g_inasm_operand_kinds[uVar12].fields + 1;
  cVar3 = *pcVar14;
  puVar5 = local_30;
  while (local_30 = puVar5, cVar3 != '\0') {
    switch(cVar3) {
    case 'b':
      local_30 = (uint32_t *)((int)puVar5 + 1);
      if ((char)*puVar5 != -1) {
        local_28 = (int)(char)*puVar5 + 1;
      }
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x34b);
    case 'd':
    case 'o':
      local_30 = puVar5 + 1;
      uVar13 = *puVar5;
      break;
    case 'g':
      local_30 = (uint32_t *)((int)puVar5 + 1);
      if ((char)*puVar5 != 0) {
        local_18 = (char)*puVar5 + -7;
      }
      break;
    case 'i':
      local_30 = (uint32_t *)((int)puVar5 + 1);
      local_20 = (int)(char)*puVar5 + 1;
      break;
    case 'r':
      local_30 = (uint32_t *)((int)puVar5 + 1);
      iVar7 = (int)(char)*puVar5;
      if (uVar12 == 1) {
        if ((g_x86_op_flags[op] & 1) == 0) {
          if ((g_x86_op_flags[op] & 0x2000) == 0) {
            if ((iVar7 < 8) && (size != 1)) {
              if (size != 2) {
                if (size != 4) {
                  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x2f9);
                }
                goto LAB_10773971;
              }
              uVar16 = iVar7 + 9;
            }
            else {
              uVar16 = iVar7 + 0x11;
            }
          }
          else if ((iVar7 < 0x28) || (0x2f < iVar7)) {
LAB_10773971:
            uVar16 = iVar7 + 1;
          }
          else {
            uVar16 = iVar7 + 0x12;
          }
        }
        else {
          uVar16 = iVar7 - 9;
        }
      }
      else if (iVar7 < 8) {
        if (iVar7 == 0) {
          uVar16 = 0x27;
        }
        else if (iVar7 == 2) {
          uVar16 = 0x28;
        }
        else {
          if (iVar7 != 3) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x30e);
          }
          uVar16 = 0x29;
        }
      }
      else {
        uVar16 = iVar7 + 0x22;
      }
      break;
    case 's':
      uVar6 = inasm_read_compact_value((uint16_t **)&local_30);
      local_24 = fe_scope_lookup_id(scope,uVar6);
      if ((local_24 != (c2_fe_symbol *)0x0) && (local_24->cls == '\x03')) {
        switch(op) {
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
          break;
        default:
          (local_24->u3e).label_flags = (local_24->u3e).label_flags | 1;
        }
      }
      goto switchD_10773a7a_caseD_e;
    case 'v':
      local_30 = puVar5 + 1;
      local_1c = *puVar5;
      break;
    case 'x':
      local_30 = (uint32_t *)((int)puVar5 + 1);
      local_8 = log2_floor((int)(char)*puVar5);
switchD_10773a7a_caseD_e:
    }
    pcVar1 = pcVar14 + 1;
    pcVar14 = pcVar14 + 1;
    puVar5 = local_30;
    cVar3 = *pcVar1;
  }
  if (local_10 != 0) {
    switch(uVar12) {
    case 4:
    case 5:
      goto switchD_1077393e_caseD_4;
    case 6:
    case 7:
      if (local_20 == local_14) {
        local_20 = 6;
      }
switchD_1077393e_caseD_4:
      local_24 = local_c;
      if (local_28 == local_14) {
        local_28 = 6;
      }
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x35e);
    }
  }
  if ((local_24 != (c2_fe_symbol *)0x0) &&
     (((uVar4 = local_24->cls, uVar4 == '\x01' || (uVar4 == '\x04')) ||
      ((uVar4 == '\x03' && (uVar12 != 10)))))) {
    local_2c = fe_symbol_get_storage(local_24);
  }
  if (((g_x86_op_flags[op] & 1) == 0) || ((int)size < 4)) {
    if ((g_x86_op_flags[op] & 0x2000) == 0) {
      if (op == 0xf) {
        uVar15 = 0;
      }
      else {
        uVar15 = size | 0x1000;
      }
    }
    else {
      uVar15 = 0xa008;
    }
  }
  else {
    uVar15 = size | 0x4000;
  }
  type_00 = (uint16_t)uVar15;
  uVar6 = local_1c;
  switch(uVar12) {
  case 1:
    if ((type_00 != 0xa008) || ((0x39 < (int)uVar16 && ((int)uVar16 < 0x42)))) goto LAB_10773b84;
  case 0x14:
    type_00 = 0x1004;
LAB_10773b84:
    pcVar8 = operand_new_hardreg(uVar16 & 0xffff,type_00);
    *local_4 = pcVar8;
    return (uint8_t *)local_30;
  case 2:
    goto switchD_10773b01_caseD_2;
  case 3:
    if (local_2c != (c2_symbol *)0x0) {
      if ((int)uVar13 < 0) {
        pcVar9 = symbol_get_part(local_2c,type_00,0,0);
        pcVar8 = operand_new_sym(0x14b,type_00,pcVar9);
        piVar2 = &pcVar8->sym->offset;
        *piVar2 = *piVar2 + uVar13;
      }
      else {
        pcVar9 = symbol_get_part(local_2c,type_00,0,uVar13);
        pcVar8 = operand_new_sym(0x14b,type_00,pcVar9);
      }
      goto LAB_10773bce;
    }
  case 0x10:
    uVar18 = 0;
    pcVar17 = (c2_operand *)0x0;
    pcVar8 = (c2_operand *)0x0;
    uVar6 = 0x152;
    pcVar9 = (c2_symbol *)0x0;
    break;
  case 4:
  case 5:
    if (op == 0x12) {
      pcVar17 = (c2_operand *)0x0;
      pcVar8 = operand_new_hardreg(local_28 & 0xffff,0x1004);
      pcVar8 = operand_new_addr(0x14c,type_00,local_2c,uVar13,pcVar8,pcVar17);
      goto LAB_10773bce;
    }
    if (((local_28 == 6) && (local_2c != (c2_symbol *)0x0)) &&
       ((uVar4 = local_2c->cls, uVar4 == '\x03' ||
        (((uVar4 == '\x04' || (uVar4 == '\x05')) || (uVar4 == '\x06')))))) {
      pcVar9 = symbol_get_part(local_2c,type_00,uVar15 & 0xfff,uVar13);
      pcVar8 = operand_new_sym(0x14a,type_00,pcVar9);
      *local_4 = pcVar8;
      return (uint8_t *)local_30;
    }
    uVar18 = 0;
    pcVar17 = (c2_operand *)0x0;
    pcVar8 = operand_new_hardreg(local_28 & 0xffff,0x1004);
    uVar6 = 0x14c;
    pcVar9 = local_2c;
    break;
  case 6:
  case 7:
    if (op == 0x12) {
      if (local_28 == 0) {
        pcVar8 = operand_new_hardreg(local_20 & 0xffff,0x1004);
        pcVar8 = operand_new_addr(0x14f,type_00,local_2c,uVar13,(c2_operand *)0x0,pcVar8);
      }
      else {
        pcVar8 = operand_new_hardreg(local_20 & 0xffff,0x1004);
        pcVar17 = operand_new_hardreg(local_28 & 0xffff,0x1004);
        pcVar8 = operand_new_addr(0x14d,type_00,local_2c,uVar13,pcVar17,pcVar8);
      }
    }
    else {
      uVar6 = 0;
      if (local_28 == 0) {
        pcVar8 = operand_new_hardreg(local_20 & 0xffff,0x1004);
        uVar18 = 0x14f;
        pcVar17 = (c2_operand *)0x0;
      }
      else {
        pcVar8 = operand_new_hardreg(local_20 & 0xffff,0x1004);
        pcVar17 = operand_new_hardreg(local_28 & 0xffff,0x1004);
        uVar18 = 0x14d;
      }
      pcVar8 = operand_new_mem(uVar18,type_00,local_2c,uVar13,pcVar17,pcVar8,uVar6);
    }
    pcVar8->flags11 = (pcVar8->flags11 ^ (byte)local_18) & 7 ^ pcVar8->flags11;
    pcVar8->flags = (pcVar8->flags ^ (byte)local_8) & 0xf ^ pcVar8->flags;
    *local_4 = pcVar8;
    return (uint8_t *)local_30;
  case 8:
    if ((int)op < 0x116) {
      if (op != 0x115) {
        switch(op) {
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
          break;
        default:
          goto switchD_10773b01_caseD_9;
        }
      }
    }
    else if (op != 0x11b) goto switchD_10773b01_caseD_9;
    uVar6 = uVar13;
    if (local_24 == (c2_fe_symbol *)0x0) {
switchD_10773b01_caseD_c:
      local_1c = uVar6;
      pcVar8 = operand_new_addr(0x156,0x1004,(c2_symbol *)0x0,local_1c,(c2_operand *)0x0,
                                (c2_operand *)0x0);
      *local_4 = pcVar8;
      return (uint8_t *)local_30;
    }
    if (uVar13 == 0) goto switchD_10773b01_caseD_a;
  case 9:
switchD_10773b01_caseD_9:
    uVar6 = uVar13;
    if (local_2c != (c2_symbol *)0x0) {
      pcVar8 = operand_new_addr((uVar12 != 8) + 0x150,type_00,local_2c,uVar13,(c2_operand *)0x0,
                                (c2_operand *)0x0);
      *local_4 = pcVar8;
      return (uint8_t *)local_30;
    }
switchD_10773b01_caseD_2:
    local_1c = uVar6;
    type = 0x1001;
    if ((uVar15 & 0xfff) < 5) {
      type = type_00;
    }
    pcVar11 = operand_new_intconst(type,local_1c,(int)local_1c >> 0x1f);
    *local_4 = pcVar11;
    return (uint8_t *)local_30;
  case 10:
switchD_10773b01_caseD_a:
    if (local_24->cls != '\x04') {
      pcVar10 = fe_scope_lookup_id(scope,local_24->id);
      uVar13 = 0x154;
      if (pcVar10 != (c2_fe_symbol *)0x0) goto LAB_10773ede;
    }
    uVar13 = 0x153;
LAB_10773ede:
    pcVar8 = operand_new_codeaddr(uVar13,local_24);
    *local_4 = pcVar8;
    return (uint8_t *)local_30;
  case 0xb:
    pcVar11 = operand_new_intconst(0x1004,0,0);
    pcVar11->op = 0x157;
    *local_4 = pcVar11;
    return (uint8_t *)local_30;
  case 0xc:
    goto switchD_10773b01_caseD_c;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\inasm.c",0x42f);
  }
  pcVar8 = operand_new_mem(uVar6,type_00,pcVar9,uVar13,pcVar8,pcVar17,uVar18);
LAB_10773bce:
  pcVar8->flags11 = (pcVar8->flags11 ^ (byte)local_18) & 7 ^ pcVar8->flags11;
  *local_4 = pcVar8;
  return (uint8_t *)local_30;
}

