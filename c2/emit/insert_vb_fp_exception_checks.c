void __fastcall insert_vb_fp_exception_checks(c2_function *fn)

{
  byte bVar1;
  ushort uVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  c2_const_operand *src2;
  c2_fe_symbol *sym;
  ushort uVar6;
  uint32_t op;
  uint8_t uVar7;
  c2_node *target;
  c2_tuple *pcVar8;
  code *insert_fn_00;
  c2_tuple *pcVar9;
  c2_insert_fn *insert_fn;
  
  pcVar9 = fn->cfg->first->head;
  uVar7 = pcVar9->kind;
  pcVar8 = g_vb_entry_tail_chain;
  do {
    g_vb_entry_tail_chain = pcVar8;
    if (uVar7 == '\x18') {
      pcVar9 = pcVar9->prev;
      uVar6 = pcVar9->line;
      if (uVar6 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar6;
        g_cur_line = uVar6;
      }
      pcVar5 = pcVar8;
      if (pcVar8 != (c2_tuple *)0x0) {
        for (; pcVar5 != (c2_tuple *)0x0; pcVar5 = pcVar5->next) {
          if (pcVar5->op == 0x184) {
            pcVar5->op = 0xe;
          }
        }
        tuple_splice_after(pcVar9,pcVar8);
        g_vb_entry_tail_chain = (c2_tuple *)0x0;
      }
      if (g_vb_fp_error_label != (c2_tuple *)0x0) {
        tuple_insert_after(pcVar9,g_vb_fp_error_label);
        insert_fn_00 = tuple_insert_after;
        pcVar8 = (c2_tuple *)0x0;
        pcVar4 = (c2_operand *)0x0;
        pcVar9 = g_vb_fp_error_label;
        sym = fe_symbol_lookup_name("___vbaFPException");
        pcVar3 = operand_new_codeaddr(0x153,sym);
        tuple_new_branch(0x10,'\0',(c2_node *)pcVar3,pcVar4,pcVar8,insert_fn_00,pcVar9);
        g_vb_fp_error_label = (c2_tuple *)0x0;
      }
      return;
    }
    pcVar8 = pcVar9->next;
    if (pcVar9->op == 0x178) {
      uVar6 = pcVar9->type & 0xf000;
      if ((uVar6 == 0x4000) || ((pcVar9->dst->type & 0xf000) != 0x4000)) {
        uVar2 = pcVar9->line;
        if (uVar2 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar2;
          g_cur_line = uVar2;
        }
        pcVar3 = pcVar9->src;
        if ((pcVar3->type & 0xf000) == 0x4000) {
          bVar1 = pcVar8->flags;
          pcVar5 = pcVar8;
          while ((((bVar1 & 1) != 0 && ((pcVar5->type & 0xf000) != 0x4000)) &&
                 (pcVar5->kind != '\x0e'))) {
            pcVar5 = pcVar5->next;
            bVar1 = pcVar5->flags;
          }
          if (((pcVar5->op != 0x62) && (pcVar5->op != 99)) ||
             ((pcVar5->dst->kind == '\x01' || (pcVar9->dst->next->sym->cls == '\x01')))) {
            pcVar5 = pcVar9;
          }
          insert_fn = tuple_insert_after;
          pcVar3 = operand_new_reg(0x149,0x8000,g_reg_symbols + 0x4a,g_reg_symbols + 0x4a);
          pcVar4 = operand_new_reg(0x149,0x2002,g_reg_symbols + 9,g_reg_symbols + 9);
          pcVar5 = tuple_new(0x6e,0x2002,pcVar4,pcVar3,insert_fn,pcVar5);
          insert_fn = tuple_insert_after;
          src2 = operand_new_intconst(0x2001,0xd,0);
          pcVar3 = operand_new_reg(0x149,0x2001,g_reg_symbols + 0x11,g_reg_symbols + 0x11);
          pcVar4 = operand_new_reg(0x149,0x8000,g_reg_symbols + 0x4a,g_reg_symbols + 0x4a);
          pcVar5 = tuple_new_binary(0x33,0x2001,pcVar4,pcVar3,src2,insert_fn,pcVar5);
          target = *(c2_node **)((int)&pcVar9->src->next->sym->u30 + 2);
          uVar7 = '\x05';
LAB_1077b4a2:
          op = 0xf;
        }
        else {
          pcVar5 = pcVar9;
          if (pcVar3->kind != '\a') {
            target = *(c2_node **)((int)&pcVar3->next->sym->u30 + 2);
            if (uVar6 == 0x2000) {
              uVar7 = '\x02';
            }
            else {
              uVar7 = '\0';
            }
            goto LAB_1077b4a2;
          }
          if ((pcVar3->flags11 & 0x40) == 0) goto LAB_1077b4d8;
          target = *(c2_node **)((int)&pcVar3->next->sym->u30 + 2);
          op = 0x10;
          uVar7 = '\0';
        }
        tuple_new_branch(op,uVar7,target,(c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_after,pcVar5
                        );
      }
LAB_1077b4d8:
      tuple_unlink_free(pcVar9);
    }
    uVar7 = pcVar8->kind;
    pcVar9 = pcVar8;
    pcVar8 = g_vb_entry_tail_chain;
  } while( true );
}

