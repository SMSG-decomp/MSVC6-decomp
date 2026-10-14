void __cdecl asm_build_instruction_record(void)

{
  char cVar1;
  c1_asm_expr *expr;
  c1_asm_operand *pcVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  c1_symbol *pcVar6;
  void *pvVar7;
  ushort *puVar8;
  byte *pbVar9;
  char *pcVar10;
  int iStack_c;
  
  g_asm_instruction_record._1_2_ = g_asm_instruction.code;
  if ((((g_asm_opcode != 0xf) && (g_asm_opcode != 0xbd)) && (g_asm_opcode != 0x104)) &&
     ((g_asm_opcode != 0x105 && (g_asm_opcode != 0x106)))) {
    switch(g_asm_instruction._2_4_ & 0xf) {
    case 0:
      asm_build_instruction_record_operands(1);
      return;
    case 1:
      asm_build_instruction_record_operands(2);
      return;
    case 2:
      goto switchD_10623c13_caseD_2;
    case 3:
      asm_build_instruction_record_operands(8);
      return;
    case 4:
      asm_build_instruction_record_operands(10);
      return;
    case 5:
      asm_build_instruction_record_operands(6);
      return;
    default:
      asm_build_instruction_record_operands(0);
      return;
    }
  }
  asm_build_instruction_record_operands(g_asm_instruction.opcode_flags);
  return;
switchD_10623c13_caseD_2:
  g_asm_instruction_record[3] = '\x04';
  puVar8 = (ushort *)(g_asm_instruction_record + 4);
  iStack_c = 0;
  if (0 < g_asm_operand_index) {
    do {
      expr = g_asm_instruction.exprs[iStack_c];
      pcVar2 = g_asm_operand_order[iStack_c];
      if (pcVar2->sym != (c1_symbol *)0x0) {
        *(byte *)puVar8 = 0x12;
        pcVar6 = pcVar2->sym;
        sym_mark_referenced(pcVar6);
        if ((pcVar6->flags3 & 0x40) != 0) {
          pcVar6 = decl_lookup_file_scope_twin(pcVar6);
          sym_mark_referenced(pcVar6);
        }
        if ((((pcVar6->flags23 & 1) != 0) &&
            (pvVar7 = sym_segment_record(pcVar6), (*(uint *)((int)pvVar7 + 0x1c) & 0xffffff) == 5))
           && ((g_current_function != (c1_symbol *)0x0 && ((g_current_function->flags21 & 1) == 0)))
           ) {
          g_function_has_body = 1;
          g_function_auto_inline = 0;
        }
        if (g_c9il_mode == '\0') {
          if ((pcVar6->key_ref & 0xfffffff8) == 0) {
            uVar5 = il_symbol_key_assign(pcVar6);
          }
          else {
            uVar5 = pcVar6->key_ref >> 3;
          }
        }
        else {
          uVar5 = pcVar6->entity & 0xffffff;
        }
        if (uVar5 < 0x8000) {
          *(ushort *)((int)puVar8 + 1) = (ushort)uVar5;
          pbVar9 = (byte *)((int)puVar8 + 3);
        }
        else {
          *(ushort *)((int)puVar8 + 1) = (ushort)uVar5 | 0x8000;
          *(short *)((int)puVar8 + 3) = (short)(uVar5 >> 0xf);
          pbVar9 = (byte *)((int)puVar8 + 5);
        }
        *pbVar9 = 7;
        puVar8 = (ushort *)(pbVar9 + 1);
      }
      pcVar2 = g_asm_operand_order[iStack_c];
      if (pcVar2->frame_sym != (c1_symbol *)0x0) {
        *(byte *)puVar8 = 0x12;
        pcVar6 = pcVar2->frame_sym;
        sym_mark_referenced(pcVar6);
        if ((pcVar6->flags3 & 0x40) != 0) {
          pcVar6 = decl_lookup_file_scope_twin(pcVar6);
          sym_mark_referenced(pcVar6);
        }
        if (((((pcVar6->flags23 & 1) != 0) &&
             (pvVar7 = sym_segment_record(pcVar6), (*(uint *)((int)pvVar7 + 0x1c) & 0xffffff) == 5))
            && (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0)
           ) {
          g_function_has_body = 1;
          g_function_auto_inline = 0;
        }
        if (g_c9il_mode == '\0') {
          if ((pcVar6->key_ref & 0xfffffff8) == 0) {
            uVar5 = il_symbol_key_assign(pcVar6);
          }
          else {
            uVar5 = pcVar6->key_ref >> 3;
          }
        }
        else {
          uVar5 = pcVar6->entity & 0xffffff;
        }
        if (uVar5 < 0x8000) {
          *(ushort *)((int)puVar8 + 1) = (ushort)uVar5;
          pbVar9 = (byte *)((int)puVar8 + 3);
        }
        else {
          *(ushort *)((int)puVar8 + 1) = (ushort)uVar5 | 0x8000;
          *(short *)((int)puVar8 + 3) = (short)(uVar5 >> 0xf);
          pbVar9 = (byte *)((int)puVar8 + 5);
        }
        *pbVar9 = 5;
        puVar8 = (ushort *)(pbVar9 + 1);
      }
      bVar3 = asm_operand_mode(expr);
      pcVar10 = (&PTR_g_empty_string_10659f9c)[bVar3];
      cVar1 = *pcVar10;
      while (cVar1 != '\0') {
        pcVar10 = pcVar10 + 1;
        switch(cVar1) {
        case 'b':
        case 'r':
          bVar4 = expr->base;
          if (bVar4 == 0x3f) {
            *(byte *)puVar8 = 0xff;
          }
          else {
LAB_10623d1a:
            bVar4 = bVar4 & 0x3f;
LAB_10623d1c:
            *(byte *)puVar8 = bVar4;
          }
          break;
        default:
          goto switchD_10623d3d_caseD_63;
        case 'd':
        case 'o':
        case 'v':
          *(int *)puVar8 = expr->disp;
          puVar8 = puVar8 + 2;
          goto switchD_10623d3d_caseD_63;
        case 'g':
          bVar4 = expr->seg_scale & 0x3f;
          if (bVar4 != 0x3f) goto LAB_10623d1c;
          *(byte *)puVar8 = 0;
          break;
        case 'i':
          bVar4 = expr->index;
          if (bVar4 != 0x3f) goto LAB_10623d1a;
          *(byte *)puVar8 = 0xff;
          break;
        case 'm':
          *(byte *)puVar8 = bVar3;
          break;
        case 's':
          pcVar6 = expr->sym;
          if (pcVar6 == (c1_symbol *)0x0) {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
          }
          else {
            sym_mark_referenced(pcVar6);
            if ((pcVar6->flags3 & 0x40) != 0) {
              pcVar6 = decl_lookup_file_scope_twin(pcVar6);
              sym_mark_referenced(pcVar6);
            }
            if ((((pcVar6->flags23 & 1) != 0) &&
                (pvVar7 = sym_segment_record(pcVar6),
                (*(uint *)((int)pvVar7 + 0x1c) & 0xffffff) == 5)) &&
               ((g_current_function != (c1_symbol *)0x0 && ((g_current_function->flags21 & 1) == 0))
               )) {
              g_function_has_body = 1;
              g_function_auto_inline = 0;
            }
            if (g_c9il_mode == '\0') {
              if ((pcVar6->key_ref & 0xfffffff8) == 0) {
                uVar5 = il_symbol_key_assign(pcVar6);
              }
              else {
                uVar5 = pcVar6->key_ref >> 3;
              }
            }
            else {
              uVar5 = pcVar6->entity & 0xffffff;
            }
            if (uVar5 < 0x8000) {
              *puVar8 = (ushort)uVar5;
              puVar8 = puVar8 + 1;
            }
            else {
              *puVar8 = (ushort)uVar5 | 0x8000;
              puVar8[1] = (ushort)(uVar5 >> 0xf);
              puVar8 = puVar8 + 2;
            }
          }
          goto switchD_10623d3d_caseD_63;
        case 'x':
          *(char *)puVar8 = '\x01' << (expr->seg_scale >> 6);
        }
        puVar8 = (ushort *)((int)puVar8 + 1);
switchD_10623d3d_caseD_63:
        cVar1 = *pcVar10;
      }
      iStack_c = iStack_c + 1;
    } while (iStack_c < g_asm_operand_index);
  }
  g_asm_instruction_record[0] = (char)puVar8 + 'D';
  return;
}

