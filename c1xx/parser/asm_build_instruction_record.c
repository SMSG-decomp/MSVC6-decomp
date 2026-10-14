void asm_build_instruction_record(void)

{
  c1_asm_operand_slot **ppcVar1;
  char cVar2;
  c1_asm_operand *operand;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  c1_u8 *key_end;
  c1_u8 *key_end_2;
  c1_symbol *pcVar6;
  c1_u8 *out;
  c1_symbol *pcVar7;
  char *pcVar8;
  int local_c;
  
  g_asm_instruction_record.opcode = g_asm_record_code;
  if ((((g_asm_instruction_code == 0xf) || (g_asm_instruction_code == 0xbd)) ||
      (g_asm_instruction_code == 0x104)) ||
     ((g_asm_instruction_code == 0x105 || (g_asm_instruction_code == 0x106)))) {
    g_asm_instruction_record.operand_form = g_asm_condition_code;
  }
  else {
    switch(_g_asm_size_class & 0xf) {
    case 0:
      g_asm_instruction_record.operand_form = '\x01';
      break;
    case 1:
      g_asm_instruction_record.operand_form = '\x02';
      break;
    case 2:
      g_asm_instruction_record.operand_form = '\x04';
      break;
    case 3:
      g_asm_instruction_record.operand_form = '\b';
      break;
    case 4:
      g_asm_instruction_record.operand_form = '\n';
      break;
    case 5:
      g_asm_instruction_record.operand_form = '\x06';
      break;
    default:
      g_asm_instruction_record.operand_form = '\0';
    }
  }
  out = g_asm_instruction_record.operands;
  local_c = 0;
  if (0 < g_asm_operand_index) {
    do {
      operand = g_asm_emit_records[local_c];
      ppcVar1 = g_asm_emit_slots + local_c;
      if (g_asm_emit_slots[local_c]->ref_symbol != (c1_symbol *)0x0) {
        *out = '\x12';
        pcVar7 = (*ppcVar1)->ref_symbol;
        if ((pcVar7->kind & 0x1f) == 8) {
          sym_mark_enclosing_scopes(pcVar7);
        }
        sym_mark_referenced(pcVar7);
        if ((pcVar7->flags4 & 0x40) == 0) {
          bVar3 = pcVar7->kind & 0x1f;
          if ((bVar3 == 7) || (bVar3 == 8)) {
            if ((*(byte *)((int)&pcVar7->tail + 10) & 0x80) != 0) {
              sym_redeclaration_group_add(&g_map_region_queue,pcVar7);
            }
            if ((*(byte *)((int)&pcVar7->tail + 9) & 2) != 0) {
              pcVar6 = class_scalar_deleting_dtor_of(pcVar7);
              goto LAB_104ba56f;
            }
          }
        }
        else {
          bVar3 = pcVar7->kind & 0x1f;
          if (bVar3 == 3) {
            pcVar6 = sym_static_member_stand_in(pcVar7);
            pcVar7 = pcVar6;
          }
          else if (bVar3 == 10) {
            pcVar6 = sym_inline_instance_of(pcVar7);
            pcVar7 = pcVar6;
          }
          else {
            pcVar7 = (c1_symbol *)0x0;
            pcVar6 = (c1_symbol *)0x0;
          }
LAB_104ba56f:
          sym_mark_referenced(pcVar6);
        }
        if (((((pcVar7->flags23 & 1) != 0) &&
             (pcVar6 = sym_segment_record(pcVar7), (pcVar6->entity & 0xffffff) == 5)) &&
            (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0)) {
          g_function_has_body = 1;
          g_function_auto_inline = 0;
        }
        uVar5 = il_symbol_key(&pcVar7->kind);
        key_end_2 = (c1_u8 *)asm_record_put_symbol_key((c1_u16 *)(out + 1),uVar5);
        *key_end_2 = '\a';
        out = key_end_2 + 1;
      }
      if ((*ppcVar1)->frame_symbol != (c1_symbol *)0x0) {
        *out = '\x12';
        pcVar7 = (*ppcVar1)->frame_symbol;
        if ((pcVar7->kind & 0x1f) == 8) {
          sym_mark_enclosing_scopes(pcVar7);
        }
        sym_mark_referenced(pcVar7);
        if ((pcVar7->flags4 & 0x40) == 0) {
          bVar3 = pcVar7->kind & 0x1f;
          if ((bVar3 == 7) || (bVar3 == 8)) {
            if ((*(byte *)((int)&pcVar7->tail + 10) & 0x80) != 0) {
              sym_redeclaration_group_add(&g_map_region_queue,pcVar7);
            }
            if ((*(byte *)((int)&pcVar7->tail + 9) & 2) != 0) {
              pcVar6 = class_scalar_deleting_dtor_of(pcVar7);
              goto LAB_104ba64d;
            }
          }
        }
        else {
          bVar3 = pcVar7->kind & 0x1f;
          if (bVar3 == 3) {
            pcVar6 = sym_static_member_stand_in(pcVar7);
            pcVar7 = pcVar6;
          }
          else if (bVar3 == 10) {
            pcVar6 = sym_inline_instance_of(pcVar7);
            pcVar7 = pcVar6;
          }
          else {
            pcVar7 = (c1_symbol *)0x0;
            pcVar6 = (c1_symbol *)0x0;
          }
LAB_104ba64d:
          sym_mark_referenced(pcVar6);
        }
        if ((((pcVar7->flags23 & 1) != 0) &&
            (pcVar6 = sym_segment_record(pcVar7), (pcVar6->entity & 0xffffff) == 5)) &&
           ((g_current_function != (c1_symbol *)0x0 && ((g_current_function->flags21 & 1) == 0)))) {
          g_function_has_body = 1;
          g_function_auto_inline = 0;
        }
        uVar5 = il_symbol_key(&pcVar7->kind);
        key_end = (c1_u8 *)asm_record_put_symbol_key((c1_u16 *)(out + 1),uVar5);
        *key_end = '\x05';
        out = key_end + 1;
      }
      bVar3 = asm_operand_mode((int *)operand);
      pcVar8 = g_asm_mode_formats[bVar3];
      cVar2 = *pcVar8;
      while (cVar2 != '\0') {
        pcVar8 = pcVar8 + 1;
        switch(cVar2) {
        case 'b':
        case 'r':
          bVar4 = operand->base;
          goto LAB_1045674f;
        case 'd':
        case 'o':
        case 'v':
          *(int *)out = operand->value;
          out = out + 4;
          break;
        case 'g':
          bVar4 = operand->seg_scale & 0x3f;
          if (bVar4 != 0x3f) goto LAB_10456769;
          *out = '\0';
          goto LAB_1045676b;
        case 'i':
          bVar4 = operand->index;
LAB_1045674f:
          if (bVar4 != 0x3f) {
            bVar4 = bVar4 & 0x3f;
            goto LAB_10456769;
          }
          *out = 0xff;
          goto LAB_1045676b;
        case 'm':
          bVar4 = bVar3;
          goto LAB_10456769;
        case 's':
          pcVar7 = operand->sym;
          if (pcVar7 == (c1_symbol *)0x0) {
            out[0] = '\0';
            out[1] = '\0';
            out = out + 2;
          }
          else {
            if ((pcVar7->kind & 0x1f) == 8) {
              sym_mark_enclosing_scopes(pcVar7);
            }
            sym_mark_referenced(pcVar7);
            if ((pcVar7->flags4 & 0x40) == 0) {
              bVar4 = pcVar7->kind & 0x1f;
              if ((bVar4 == 7) || (bVar4 == 8)) {
                if ((*(byte *)((int)&pcVar7->tail + 10) & 0x80) != 0) {
                  sym_redeclaration_group_add(&g_map_region_queue,pcVar7);
                }
                if ((*(byte *)((int)&pcVar7->tail + 9) & 2) != 0) {
                  pcVar6 = class_scalar_deleting_dtor_of(pcVar7);
                  goto LAB_104ba733;
                }
              }
            }
            else {
              bVar4 = pcVar7->kind & 0x1f;
              if (bVar4 == 3) {
                pcVar6 = sym_static_member_stand_in(pcVar7);
                pcVar7 = pcVar6;
              }
              else if (bVar4 == 10) {
                pcVar6 = sym_inline_instance_of(pcVar7);
                pcVar7 = pcVar6;
              }
              else {
                pcVar7 = (c1_symbol *)0x0;
                pcVar6 = (c1_symbol *)0x0;
              }
LAB_104ba733:
              sym_mark_referenced(pcVar6);
            }
            if (((((pcVar7->flags23 & 1) != 0) &&
                 (pcVar6 = sym_segment_record(pcVar7), (pcVar6->entity & 0xffffff) == 5)) &&
                (g_current_function != (c1_symbol *)0x0)) &&
               ((g_current_function->flags21 & 1) == 0)) {
              g_function_has_body = 1;
              g_function_auto_inline = 0;
            }
            uVar5 = il_symbol_key(&pcVar7->kind);
            out = (c1_u8 *)asm_record_put_symbol_key((c1_u16 *)out,uVar5);
          }
          break;
        case 'x':
          bVar4 = '\x01' << (operand->seg_scale >> 6);
LAB_10456769:
          *out = bVar4;
LAB_1045676b:
          out = out + 1;
        }
        cVar2 = *pcVar8;
      }
      local_c = local_c + 1;
    } while (local_c < g_asm_operand_index);
  }
  g_asm_instruction_record.length = (char)out + 'p';
  return;
}

