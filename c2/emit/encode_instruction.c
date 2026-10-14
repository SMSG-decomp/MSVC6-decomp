int __fastcall
encode_instruction(c2_tuple *t,uint8_t *buf,int32_t code_offset,int emit_relocs,
                  c2_fe_symbol *section)

{
  uint8_t uVar1;
  sbyte sVar2;
  uint8_t uVar3;
  c2_symbol *pcVar4;
  c2_function *pcVar5;
  char cVar6;
  uint uVar7;
  uint8_t *form_code;
  int iVar8;
  uint32_t uVar9;
  byte bVar10;
  byte *pbVar11;
  c2_operand *opnd;
  byte *pbVar12;
  uint8_t *puVar13;
  c2_operand *pcVar14;
  c2_operand *opnd_00;
  uint8_t *puVar15;
  bool bVar16;
  uint uVar17;
  uint8_t *opcode_ptr;
  
  pcVar5 = g_cur_function;
  uVar17 = t->op;
  if ((uVar17 == 0) || (0x143 < uVar17)) {
    return 0;
  }
  uVar7 = g_x86_op_flags[uVar17];
  if ((uVar7 & 0x2000) != 0) {
    g_cur_function->flags = g_cur_function->flags | 0x40000;
  }
  if (uVar17 == 0xe5) {
    pcVar5->flags = pcVar5->flags | 0x80000;
  }
  g_encode_emit_relocs = emit_relocs;
  uVar1 = t->kind;
  g_encode_insn_offset = code_offset;
  opcode_ptr = buf;
  g_encode_buffer = buf;
  switch(uVar1) {
  case '\f':
    emit_relocs = t->type & 0xfff;
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0xce);
  case '\x0e':
    emit_relocs = (-(uint)(uVar17 != 0xe) & 2) + 4;
    break;
  case '\x0f':
    emit_relocs = 0;
    break;
  case '\x11':
    if (uVar17 < 0x114) {
      if (uVar17 != 0x113) {
        switch(uVar17) {
        case 0xf:
        case 0x10:
          emit_relocs = 4;
          goto LAB_10735356;
        default:
switchD_1073540d_caseD_11:
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",200);
        case 0x16:
          opcode_ptr = buf + 1;
          *buf = 'g';
          break;
        case 0x17:
        case 0x18:
        case 0x19:
          break;
        }
      }
    }
    else {
      if (uVar17 == 0x114) {
        emit_relocs = 6;
        break;
      }
      if ((uVar17 != 0x115) && (uVar17 != 0x11b)) goto switchD_1073540d_caseD_11;
    }
    emit_relocs = 1;
  }
LAB_10735356:
  sVar2 = g_x86_op_operand_count[uVar17];
  if ((uVar7 & 0x800) == 0) {
    opnd = t->src;
    if (opnd == (c2_operand *)0x0) {
      opnd_00 = (c2_operand *)0x0;
    }
    else {
      opnd_00 = opnd->next;
    }
  }
  else {
    opnd = t->dst;
    opnd_00 = t->src;
  }
  if ((uVar7 & 0x200) != 0) {
    *opcode_ptr = 0x9b;
    opcode_ptr = opcode_ptr + 1;
  }
  if ((emit_relocs == 2) && ((uVar7 & 0x21) == 0)) {
    *opcode_ptr = 'f';
    opcode_ptr = opcode_ptr + 1;
  }
  if (((0 < sVar2) && (bVar10 = opnd->flags11, (bVar10 & 7) != 0)) ||
     ((1 < sVar2 && (bVar10 = opnd_00->flags11, (bVar10 & 7) != 0)))) {
    uVar7 = (bVar10 & 7) + 0x18;
    if (uVar7 < 0x1d) {
      *opcode_ptr = (*(byte *)&g_reg_symbols[uVar7].u28 & 3) << 3 | 0x26;
    }
    else {
      *opcode_ptr = (uVar7 != 0x1d) + 'd';
    }
    opcode_ptr = opcode_ptr + 1;
  }
  form_code = g_x86_form_code[uVar17];
  code_offset = (int32_t)(g_x86_form_opcode + uVar17);
LAB_107354b6:
  g_encode_cursor = opcode_ptr;
  if ((g_x86_op_flags[uVar17] & 0x10) != 0) {
    *opcode_ptr = '\x0f';
    g_encode_cursor = opcode_ptr + 1;
  }
  pbVar12 = g_encode_cursor;
  pbVar11 = g_encode_cursor + 1;
  *g_encode_cursor = *(uint8_t *)code_offset;
  switch(*form_code & 0x1f) {
  case 1:
    goto switchD_107354f4_caseD_1;
  case 2:
    uVar3 = opnd_00->kind;
    if (((uVar3 == '\a') || (uVar3 == '\b')) ||
       (((uVar3 == '\x04' || ((uVar3 == '\x03' && (opnd_00->op != 0x14a)))) ||
        ((uVar3 == '\x05' && ((opnd_00->op == 0x150 || (opnd_00->op == 0x151)))))))) {
      g_encode_cursor = pbVar11;
      encode_modrm(t,opnd,(int)g_x86_modrm_ext[uVar17] >> 3);
      uVar17 = *form_code & 0x20;
      opcode_ptr = pbVar12;
      goto LAB_10735524;
    }
    break;
  case 3:
    uVar9 = opnd->op;
    if ((((uVar9 == 0x149) && (((opnd->u18).reg)->storage->id == 1)) &&
        (((opnd->u18).reg)->id != 0x15)) &&
       (((opnd_00->op == 0x14b && (opnd_00->kind == '\x02')) || (opnd_00->op == 0x152)))) {
      g_encode_cursor = pbVar11;
      encode_imm_or_disp(opnd_00,4,0);
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    }
    if (((opnd_00->op == 0x149) && (((opnd_00->u18).reg)->storage->id == 1)) &&
       ((((opnd_00->u18).reg)->id != 0x15 &&
        (((uVar9 == 0x14b && (opnd->kind == '\x02')) || (uVar9 == 0x152)))))) {
      g_encode_cursor = pbVar11;
      encode_imm_or_disp(opnd,4,0);
      *pbVar12 = *pbVar12 | 2;
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    }
    break;
  case 4:
    uVar3 = opnd->kind;
    if ((((uVar3 == '\a') || (uVar3 == '\b')) || (uVar3 == '\x04')) ||
       (((uVar3 == '\x03' && (opnd->op != 0x14a)) ||
        ((uVar3 == '\x05' && ((opnd->op == 0x150 || (opnd->op == 0x151)))))))) {
      g_encode_cursor = pbVar11;
      bVar10 = encode_imm_or_disp(opnd,emit_relocs,1);
      *pbVar12 = *pbVar12 | bVar10;
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    }
    break;
  case 5:
    if ((opnd->op == 0x149) &&
       (((((uVar3 = opnd_00->kind, uVar3 == '\a' || (uVar3 == '\b')) || (uVar3 == '\x04')) ||
         ((uVar3 == '\x03' && (opnd_00->op != 0x14a)))) ||
        ((uVar3 == '\x05' && ((opnd_00->op == 0x150 || (opnd_00->op == 0x151)))))))) {
      bVar10 = *g_encode_cursor | *(byte *)&((opnd->u18).reg)->u28;
      *g_encode_cursor = bVar10;
      g_encode_cursor = pbVar11;
      if (1 < (uint)emit_relocs) {
        *pbVar12 = bVar10 | 8;
      }
      encode_imm_or_disp(opnd_00,emit_relocs,0);
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    }
    break;
  case 6:
    if ((opnd->op == 0x149) && (emit_relocs != 1)) {
      *g_encode_cursor = *g_encode_cursor | *(byte *)&((opnd->u18).reg)->u28;
      g_encode_cursor = pbVar11;
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    }
    break;
  case 7:
    if (g_x86_modrm_ext[uVar17] != 0) {
      *pbVar11 = g_x86_modrm_ext[uVar17];
      pbVar11 = g_encode_cursor + 2;
    }
    goto LAB_107359f7;
  case 8:
    if (emit_relocs == 1) {
      if ((opnd->kind == '\x04') || (opnd->op == 0x156)) {
        g_encode_cursor = pbVar11;
        encode_imm_or_disp(opnd,1,0);
        pbVar11 = g_encode_cursor;
        goto LAB_107359f7;
      }
      if (opnd->op == 0x150) {
        g_encode_cursor = pbVar11;
        opnd->op = 0x155;
        encode_imm_or_disp(opnd,1,0);
        opnd->op = 0x150;
        pbVar11 = g_encode_cursor;
        goto LAB_107359f7;
      }
    }
    break;
  case 9:
    if ((uint)emit_relocs < 5) {
      if ((opnd->kind == '\x04') || (opnd->op == 0x156)) {
        if (((opnd->op == 0x153) && (opnd->sym->cls == '\x04')) ||
           (((section != (c2_fe_symbol *)0x0 && (opnd->op == 0x154)) &&
            (opnd->sym->offset != section->id)))) {
          g_encode_cursor = pbVar11;
          encode_reloc_operand(opnd,4);
          pbVar11 = g_encode_cursor;
        }
        else {
          g_encode_cursor = pbVar11;
          encode_imm_or_disp(opnd,4,0);
          pbVar11 = g_encode_cursor;
        }
        goto LAB_107359f7;
      }
      if (opnd->op == 0x150) {
        g_encode_cursor = pbVar11;
        opnd->op = 0x155;
        encode_imm_or_disp(opnd,4,0);
        opnd->op = 0x150;
        pbVar11 = g_encode_cursor;
        goto LAB_107359f7;
      }
    }
    break;
  case 10:
    if (emit_relocs == 6) {
      if (uVar1 == '\x04') {
        if (((opnd->op == 0x153) && (opnd->sym->cls == '\x04')) ||
           ((section != (c2_fe_symbol *)0x0 &&
            ((opnd->op == 0x154 && (opnd->sym->offset != section->id)))))) {
          g_encode_cursor = pbVar11;
          encode_reloc_operand(opnd,6);
          pbVar11 = g_encode_cursor;
        }
        else {
          g_encode_cursor = pbVar11;
          encode_imm_or_disp(opnd,6,0);
          pbVar11 = g_encode_cursor;
        }
        goto LAB_107359f7;
      }
      if (opnd->op == 0x150) {
        g_encode_cursor = pbVar11;
        opnd->op = 0x155;
        encode_imm_or_disp(opnd,6,0);
        opnd->op = 0x150;
        pbVar11 = g_encode_cursor;
        goto LAB_107359f7;
      }
    }
    break;
  case 0xb:
    if (((opnd->op != 0x149) || (uVar7 = ((opnd->u18).reg)->id, uVar7 < 0x19)) || (0x1e < uVar7)) {
      if (((opnd_00->op != 0x149) || (uVar7 = ((opnd_00->u18).reg)->id, uVar7 < 0x19)) ||
         (0x1e < uVar7)) break;
      uVar9 = (uint)((opnd_00->u18).range)->first_block & 7;
      g_encode_cursor = pbVar11;
      goto LAB_10735c6f;
    }
    g_encode_cursor = pbVar11;
    encode_modrm(t,opnd_00,(uint)((opnd->u18).range)->first_block & 7);
    *pbVar12 = *pbVar12 | 2;
    pbVar11 = g_encode_cursor;
    goto LAB_107359f7;
  case 0xc:
    if (((opnd->op == 0x149) && (uVar7 = ((opnd->u18).reg)->id, 0x18 < uVar7)) && (uVar7 < 0x1f)) {
      pcVar4 = (opnd->u18).reg;
      bVar10 = *(byte *)code_offset;
      g_encode_cursor = buf + 1;
      *buf = bVar10;
      pbVar12 = buf;
      if (pcVar4->id < 0x1d) {
        *buf = bVar10 | (*(byte *)&pcVar4->u28 & 3) << 3;
        pbVar11 = g_encode_cursor;
      }
      else {
        bVar10 = *(byte *)&pcVar4->u28;
        *buf = 0xf;
        *g_encode_cursor = (bVar10 & 7) << 3 | (uVar17 != 0xd) + 0x80U;
        pbVar11 = buf + 2;
      }
      goto LAB_107359f7;
    }
    break;
  case 0xd:
    if (uVar17 < 0x6f) {
      if (uVar17 == 0x6e) {
switchD_1073583f_caseD_6c:
        if (opnd->op != 0x149) break;
        uVar9 = 4;
        g_encode_cursor = pbVar11;
        goto LAB_10735c6f;
      }
      switch(uVar17) {
      case 4:
        g_encode_cursor = pbVar11;
        emit_value_bytes((opnd->u18).lo,2);
        emit_value_bytes((opnd_00->u18).lo,1);
        pbVar11 = g_encode_cursor;
        goto LAB_107359f7;
      default:
        goto switchD_10735822_caseD_a4;
      case 7:
        uVar9 = (opnd->u18).lo;
        if (uVar9 != 3) {
          *g_encode_cursor = *g_encode_cursor | 1;
          *pbVar11 = (byte)uVar9;
          pbVar11 = g_encode_cursor + 2;
        }
        goto LAB_107359f7;
      case 8:
        g_encode_cursor = pbVar11;
        if ((opnd->u18).lo == 0) goto LAB_1073599e;
        emit_value_bytes((opnd->u18).lo,2);
        pbVar11 = g_encode_cursor;
        goto LAB_107359f7;
      case 9:
        if (emit_relocs != 1) {
          if ((((opnd->op == 0x149) && (((opnd->u18).reg)->storage->id == 1)) &&
              (((opnd->u18).reg)->id != 0x15)) && (opnd_00->op == 0x149)) {
            *g_encode_cursor = *g_encode_cursor | *(byte *)&((opnd_00->u18).reg)->u28;
            g_encode_cursor = pbVar11;
            pbVar11 = g_encode_cursor;
          }
          else {
            if (((opnd_00->op != 0x149) || (((opnd_00->u18).reg)->storage->id != 1)) ||
               ((((opnd_00->u18).reg)->id == 0x15 || (opnd->op != 0x149)))) goto LAB_107354a0;
            *g_encode_cursor = *g_encode_cursor | *(byte *)&((opnd->u18).reg)->u28;
            g_encode_cursor = pbVar11;
            pbVar11 = g_encode_cursor;
          }
          goto LAB_107359f7;
        }
        goto LAB_107354a0;
      case 10:
        if (opnd_00->op == 0x146) {
          bVar10 = *(byte *)&opnd_00->u18;
          *g_encode_cursor = *(uint8_t *)(code_offset + 1);
          *pbVar11 = bVar10;
LAB_1076c1de:
          pbVar11 = g_encode_cursor + 2;
        }
        break;
      case 0xb:
        if (opnd->op == 0x146) {
          bVar10 = *(byte *)&opnd->u18;
          *g_encode_cursor = *(uint8_t *)(code_offset + 1);
          *pbVar11 = bVar10;
          goto LAB_1076c1de;
        }
        break;
      case 0xf:
        *g_encode_cursor = '\x0f';
        uVar1 = opnd->kind;
        *pbVar11 = *(byte *)(code_offset + 1) | (byte)t->type;
        g_encode_cursor = g_encode_cursor + 2;
        if ((uVar1 != '\x04') ||
           (((opnd->op != 0x153 || (opnd->sym->cls != '\x04')) &&
            ((section == (c2_fe_symbol *)0x0 ||
             ((opnd->op != 0x154 || (opnd->sym->offset == section->id)))))))) goto LAB_10735a37;
        encode_reloc_operand(opnd,emit_relocs);
        pbVar11 = g_encode_cursor;
        goto LAB_107359f7;
      case 0x56:
        emit_relocs = opnd_00->type & 0xfff;
        goto LAB_1073587b;
      case 0x5b:
LAB_1073587b:
        if (emit_relocs != 8) goto LAB_107354a0;
        *g_encode_cursor = *g_encode_cursor | 4;
        g_encode_cursor = pbVar11;
        if (uVar17 != 0x56) {
          opnd_00 = opnd;
        }
        uVar9 = (int)((int)g_x86_modrm_ext[uVar17] | 0x28U) >> 3;
        opnd = opnd_00;
        goto LAB_10735c6f;
      case 0x60:
        goto switchD_1073583f_caseD_60;
      case 0x62:
        if (emit_relocs == 10) {
          g_encode_cursor = pbVar11;
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x23c);
        }
      case 99:
        if (opnd->op == 0x149) {
          *g_encode_cursor = *g_encode_cursor | 4;
          g_encode_cursor = pbVar11;
          uVar9 = (int)g_x86_modrm_ext[uVar17] >> 3;
        }
        else {
switchD_1073583f_caseD_60:
          if ((emit_relocs != 10) || ((uVar17 == 0x60 && (opnd_00->op == 0x149))))
          goto LAB_107354a0;
          *g_encode_cursor = *g_encode_cursor | 2;
          g_encode_cursor = pbVar11;
          if (uVar17 != 0x60) {
            opnd_00 = opnd;
          }
          uVar9 = (int)((int)g_x86_modrm_ext[uVar17] | 0x28U) >> 3;
          opnd = opnd_00;
        }
        goto LAB_10735c6f;
      case 0x6c:
        goto switchD_1073583f_caseD_6c;
      }
      g_encode_cursor = pbVar11;
      pbVar11 = g_encode_cursor;
      if ((g_x86_op_flags[uVar17] & 1) == 0) {
LAB_1076c1f3:
        pbVar11 = g_encode_cursor;
        if (emit_relocs != 1) {
LAB_1073599e:
          *pbVar12 = *pbVar12 | 1;
          pbVar11 = g_encode_cursor;
        }
      }
      goto LAB_107359f7;
    }
    switch(uVar17) {
    case 0xa3:
      g_encode_cursor = pbVar11;
      encode_modrm(t,opnd_00,(((opnd->u18).reg)->u28).frame_home);
      bVar10 = encode_imm_or_disp(opnd_00->next,emit_relocs,1);
      *pbVar12 = *pbVar12 | bVar10;
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    default:
switchD_10735822_caseD_a4:
      g_encode_cursor = pbVar11;
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x2eb);
    case 0xa9:
      if (emit_relocs == 0) {
        emit_relocs = (int)t->flags12;
      }
      if (6 < (uint)emit_relocs) {
        uVar17 = (uint)emit_relocs / 7;
        emit_relocs = (uint)emit_relocs % 7;
        pbVar11 = g_encode_cursor;
        do {
          g_encode_cursor = pbVar11 + 7;
          uVar17 = uVar17 - 1;
          *(byte (*) [4])pbVar11 = (byte  [4])0x24a48d;
          *(undefined2 *)(pbVar11 + 4) = 0;
          pbVar11[6] = 0;
          pbVar11 = g_encode_cursor;
        } while (uVar17 != 0);
      }
      pbVar11 = g_encode_cursor;
      if (emit_relocs != 0) {
        puVar13 = g_nop_fill[emit_relocs];
        puVar15 = g_encode_cursor;
        for (uVar17 = (uint)emit_relocs >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
          *(undefined4 *)puVar15 = *(undefined4 *)puVar13;
          puVar13 = puVar13 + 4;
          puVar15 = puVar15 + 4;
        }
        for (uVar17 = emit_relocs & 3; pbVar11 = g_encode_cursor + emit_relocs, uVar17 != 0;
            uVar17 = uVar17 - 1) {
          *puVar15 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar15 = puVar15 + 1;
        }
      }
      goto LAB_107359f7;
    case 0xbb:
      g_encode_cursor = opcode_ptr;
      if (opnd->kind == '\x04') {
        emit_value_bytes(0,emit_relocs);
        pbVar11 = g_encode_cursor;
        if (g_encode_emit_relocs != 0) {
          (*g_hook_add_reloc_dir32)(0,(c2_fe_symbol *)opnd->sym);
          pbVar11 = g_encode_cursor;
        }
      }
      else {
        emit_value_bytes((opnd->u18).lo,emit_relocs);
        pbVar11 = g_encode_cursor;
      }
      goto LAB_107359f7;
    case 0xc1:
      if (opnd_00->kind != '\a') goto LAB_107354a0;
      pcVar4 = (opnd->u18).reg;
      *opcode_ptr = *g_encode_cursor;
      g_encode_cursor = opcode_ptr + 1;
      encode_modrm(t,opnd,(pcVar4->u28).frame_home);
      uVar17 = 1;
      goto LAB_10735524;
    case 0xca:
    case 0xcb:
      if (opnd_00->op != 0x149) {
        g_encode_cursor = pbVar11;
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x1f8);
      }
      g_encode_cursor = pbVar11;
      encode_modrm(t,opnd,(((opnd_00->u18).reg)->u28).frame_home);
      if (opnd_00->next->op == 0x149) goto LAB_1073599e;
      *g_encode_cursor = *(uint8_t *)&opnd_00->next->u18;
      pbVar11 = g_encode_cursor + 1;
      goto LAB_107359f7;
    case 0xcc:
    case 0xcd:
    case 0xce:
    case 0xcf:
      if (opnd_00->kind != '\a') {
        if (opnd_00->op != 0x149) {
          g_encode_cursor = pbVar11;
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x25e);
        }
        form_code = form_code + 1;
        *g_encode_cursor = *(uint8_t *)(code_offset + 1);
        g_encode_cursor = pbVar11;
        uVar9 = (((opnd_00->u18).reg)->u28).frame_home;
        goto LAB_10735c6f;
      }
      if (opnd_00->op != 0x146) {
        g_encode_cursor = pbVar11;
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x25a);
      }
      g_encode_cursor = pbVar11;
      encode_modrm(t,opnd,(int)g_x86_modrm_ext[uVar17] >> 3);
      emit_value_bytes((opnd_00->u18).lo,1);
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    case 0xd0:
      if (((opnd->op == 0x149) && (uVar17 = ((opnd->u18).reg)->id, 0x26 < uVar17)) &&
         (uVar17 < 0x3a)) {
        *g_encode_cursor = *g_encode_cursor | 2;
        opnd = opnd_00;
      }
      else {
        uVar17 = ((opnd_00->u18).reg)->id;
      }
      if (((int)uVar17 < 0x2a) || (0x31 < (int)uVar17)) {
        if ((0x31 < (int)uVar17) && ((int)uVar17 < 0x3a)) {
          bVar10 = *g_encode_cursor | 4;
          goto LAB_1076c3bd;
        }
      }
      else {
        bVar10 = *g_encode_cursor | 1;
LAB_1076c3bd:
        *g_encode_cursor = bVar10;
      }
      pbVar11 = g_encode_cursor + 1;
      g_encode_cursor = g_encode_cursor + 2;
      *pbVar11 = ((byte)g_reg_symbols[uVar17].u28.frame_home | 0xf8) << 3 |
                 *(byte *)&((opnd->u18).reg)->u28;
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    case 0xd9:
    case 0xda:
      g_encode_cursor = pbVar11;
      encode_modrm(t,opnd,(((opnd_00->u18).reg)->u28).frame_home);
      goto LAB_1076c1f3;
    case 0xe6:
      if (emit_relocs == 8) {
        *g_encode_cursor = *g_encode_cursor | 1;
        g_encode_cursor = pbVar11;
        pbVar11 = g_encode_cursor;
      }
      g_encode_cursor = pbVar11;
      pbVar11 = g_encode_cursor;
      if (((opnd_00->kind == '\x01') && (uVar7 = ((opnd_00->u18).reg)->id, 0x39 < uVar7)) &&
         (uVar7 < 0x42)) {
        pcVar14 = opnd;
        if (opnd->kind == '\x01') {
          pcVar14 = opnd_00;
          opnd_00 = opnd;
        }
        *pbVar12 = *pbVar12 | 0x10;
        opnd = pcVar14;
        pbVar11 = g_encode_cursor;
      }
      break;
    case 0xe7:
      if (emit_relocs == 2) {
        bVar10 = *(byte *)(code_offset + 1);
        goto LAB_107359bc;
      }
      break;
    case 0x113:
      *g_encode_cursor = *g_encode_cursor | (byte)t->type;
      g_encode_cursor = pbVar11;
LAB_10735a37:
      encode_imm_or_disp(opnd,emit_relocs,0);
      pbVar11 = g_encode_cursor;
      goto LAB_107359f7;
    case 0x117:
      *g_encode_cursor = *g_encode_cursor | 8;
      g_encode_cursor = pbVar11;
      iVar8 = encode_instruction_case_8(pbVar12,opnd,t,form_code,buf,emit_relocs);
      return iVar8;
    case 0x11c:
    case 0x11d:
    case 0x11e:
    case 0x11f:
    case 0x120:
    case 0x121:
    case 0x122:
    case 0x123:
    case 0x124:
    case 0x125:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x129:
    case 0x12a:
    case 299:
      bVar10 = *g_encode_cursor | (char)t->op - 0x1cU;
LAB_107359bc:
      *g_encode_cursor = bVar10;
      g_encode_cursor = pbVar11;
      pbVar11 = g_encode_cursor;
    }
    goto switchD_107354f4_caseD_1;
  case 0xe:
    if (opnd->op != 0x149) {
      g_encode_cursor = pbVar11;
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x304);
    }
    if (sVar2 == 1) {
      uVar9 = (int)g_x86_modrm_ext[uVar17] >> 3;
      g_encode_cursor = pbVar11;
    }
    else if ((((opnd->u18).reg)->id == 0x1f) &&
            ((opnd_00->op != 0x149 || (((opnd_00->u18).reg)->id != 0x1f)))) {
      if ((*form_code & 0x20) != 0) {
        g_encode_cursor = pbVar11;
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x30f);
      }
      if (opnd_00->op != 0x149) {
        if ((*form_code & 0x40) == 0) {
          bVar16 = emit_relocs == 8;
        }
        else {
          bVar16 = emit_relocs == 2;
        }
        if (bVar16) {
          *g_encode_cursor = *g_encode_cursor | 4;
          g_encode_cursor = pbVar11;
          pbVar11 = g_encode_cursor;
        }
      }
      g_encode_cursor = pbVar11;
      uVar9 = (int)g_x86_modrm_ext[t->op] >> 3;
      opnd = opnd_00;
    }
    else {
      uVar9 = opnd_00->op;
      *g_encode_cursor = *g_encode_cursor | 4;
      g_encode_cursor = pbVar11;
      if (uVar9 != 0x149) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x30b);
      }
      uVar9 = (uint32_t)*(char *)(code_offset + 1);
    }
    goto LAB_10735c6f;
  case 0xf:
    if ((opnd->op != 0x149) || (opnd = opnd_00, opnd_00->op != 0x149)) {
      if ((*form_code & 0x40) == 0) {
        bVar16 = emit_relocs == 8;
      }
      else {
        bVar16 = emit_relocs == 2;
      }
      if (bVar16) {
        *g_encode_cursor = *g_encode_cursor | 4;
        g_encode_cursor = pbVar11;
        pbVar11 = g_encode_cursor;
      }
    }
    g_encode_cursor = pbVar11;
    uVar9 = (int)g_x86_modrm_ext[uVar17] >> 3;
    goto LAB_10735c6f;
  case 0x10:
    uVar9 = (int)g_x86_modrm_ext[uVar17] >> 3;
    g_encode_cursor = pbVar11;
    goto LAB_10735c6f;
  case 0x11:
    *pbVar11 = g_x86_modrm_ext[uVar17];
    pbVar12 = g_encode_cursor + 1;
    pbVar11 = g_encode_cursor + 2;
    goto LAB_107359f7;
  case 0x12:
    g_encode_cursor = pbVar11;
    encode_modrm(t,opnd,(int)g_x86_modrm_ext[uVar17] >> 3);
    if (opnd_00->op == 0x149) {
      *pbVar12 = *pbVar12 | *(byte *)(code_offset + 1);
      pbVar11 = g_encode_cursor;
    }
    else {
      if (((opnd_00->u18).lo == 1) && ((g_opt_cpu_target != 4 || (g_opt_favor_speed == 0)))) {
        *pbVar12 = *pbVar12 | 0x10;
        pbVar11 = g_encode_cursor;
      }
      else {
        emit_value_bytes((opnd_00->u18).lo,1);
        pbVar11 = g_encode_cursor;
      }
    }
    goto LAB_107359f7;
  case 0x13:
    goto switchD_107354f4_caseD_13;
  case 0x14:
    if ((((opnd->op == 0x149) && (((opnd->u18).reg)->storage->id == 1)) &&
        (((opnd->u18).reg)->id != 0x15)) &&
       (((((uVar3 = opnd_00->kind, uVar3 == '\a' || (uVar3 == '\b')) ||
          ((uVar3 == '\x04' || ((uVar3 == '\x03' && (opnd_00->op != 0x14a)))))) ||
         ((uVar3 == '\x05' && ((opnd_00->op == 0x150 || (opnd_00->op == 0x151)))))) &&
        ((g_encode_cursor = pbVar11, emit_relocs != 4 ||
         ((((*form_code & 0x20) == 0 || (opnd_00->op != 0x146)) ||
          (iVar8 = fits_signed_imm8((opnd_00->u18).lo), iVar8 == 0)))))))) {
      uVar17 = 0;
      opcode_ptr = pbVar12;
LAB_10735524:
      bVar10 = encode_imm_or_disp(opnd_00,emit_relocs,uVar17);
      *opcode_ptr = *opcode_ptr | bVar10;
      pbVar12 = opcode_ptr;
      pbVar11 = g_encode_cursor;
LAB_107359f7:
      g_encode_cursor = pbVar11;
      if ((((g_x86_op_flags[t->op] & 1) == 0) && ((*form_code & 0x80) != 0)) && (emit_relocs != 1))
      {
        *pbVar12 = *pbVar12 | 1;
      }
      return (int)g_encode_cursor - (int)buf;
    }
    break;
  case 0x15:
    *g_encode_cursor = *g_encode_cursor + (char)(emit_relocs >> 1);
    g_encode_cursor = pbVar11;
    pbVar11 = g_encode_cursor;
switchD_107354f4_caseD_1:
    g_encode_cursor = pbVar11;
    pbVar11 = g_encode_cursor;
    if (sVar2 == 1) {
switchD_107354f4_caseD_13:
      g_encode_cursor = pbVar11;
      uVar9 = (int)g_x86_modrm_ext[uVar17] >> 3;
      if ((emit_relocs == 6) && ((uVar17 == 0x114 || (uVar17 == 0x116)))) {
        uVar9 = uVar9 & 0xff | 1;
      }
    }
    else {
      if (opnd->op == 0x149) {
        encode_modrm(t,opnd_00,(((opnd->u18).reg)->u28).frame_home);
        pbVar11 = g_encode_cursor;
        if ((*form_code & 0x40) != 0) {
          *pbVar12 = *pbVar12 | 2;
          pbVar11 = g_encode_cursor;
        }
        goto LAB_107359f7;
      }
      if (opnd_00->op != 0x149) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x12f);
      }
      uVar9 = (((opnd_00->u18).reg)->u28).frame_home;
    }
LAB_10735c6f:
    encode_modrm(t,opnd,uVar9);
    pbVar11 = g_encode_cursor;
    goto LAB_107359f7;
  case 0x16:
    if (opnd->kind != '\x01') {
      g_encode_cursor = pbVar11;
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x33c);
    }
    cVar6 = (char)(emit_relocs >> 2);
    if (opnd_00->kind != '\a') {
      bVar10 = cVar6 + *(char *)(code_offset + 1);
      goto LAB_107359bc;
    }
    g_encode_cursor = pbVar11;
    encode_modrm(t,opnd,(int)g_x86_modrm_ext[uVar17] >> 3);
    *pbVar12 = *pbVar12 + cVar6;
    emit_value_bytes((opnd_00->u18).lo,1);
    pbVar11 = g_encode_cursor;
    goto LAB_107359f7;
  default:
    g_encode_cursor = pbVar11;
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x358);
  }
LAB_107354a0:
  code_offset = code_offset + 1;
  form_code = form_code + 1;
  goto LAB_107354b6;
}

