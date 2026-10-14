c1_node * __cdecl
expr_apply_overloaded_operator_body
          (char op_byte,uint op,c1_node *left,c1_type_chain_cell *chain_tail,
          c1_type_chain_cell *chain_head,char frame_empty,char frame_op,c1_node *frame_right,
          uint op_slot,c1_symbol *left_cell,c1_node *right,uint flag4,uint report,byte *failed)

{
  c1_type_chain_cell *pcVar1;
  c1_type_chain_cell *pcVar2;
  c1_type *type;
  c1_u8 *pcVar3;
  byte *failed_00;
  ushort uVar7;
  char cVar4;
  bool bVar5;
  byte bVar6;
  uint uVar8;
  int *winner;
  c1_node *pcVar9;
  c1_type *pcVar10;
  c1_symbol *pcVar11;
  int iVar12;
  c1_symbol *chain_class_3;
  c1_symbol *chain_class_2;
  c1_symbol *chain_class_4;
  c1_symbol *chain_class;
  short n;
  c1_symbol *pcVar13;
  undefined1 code_lo;
  
  pcVar9 = right;
  if ((char)flag4 == '\0') {
    pcVar10 = (c1_type *)0x0;
  }
  else {
    pcVar10 = left->type;
  }
  ovl_collect_operator_candidates((c1_ovl_resolution *)&stack0x00000018,op,left,right,pcVar10);
  if ((frame_empty != '\0') ||
     (cVar4 = ovl_prune_candidates_by_arity(&stack0x00000018,(void *)0x0), cVar4 == '\0')) {
    bVar5 = expr_builtin_operator_valid_for_class
                      ((byte)op,(pcVar9 != (c1_node *)0x0) + '\x01',flag4 & 0xff);
    if (!bVar5) {
      if ((char)report != '\0') {
        if (pcVar9 == (c1_node *)0x0) {
          uVar8 = 0x2a3;
          pcVar10 = left->type;
        }
        else {
          pcVar10 = left->type;
          iVar12 = type_is_class_or_enum(pcVar10);
          if (((((char)iVar12 == '\0') &&
               (iVar12 = type_is_template_type_parameter(pcVar10), (char)iVar12 == '\0')) &&
              ((pcVar10->code & 0xfff) != 0x802)) &&
             (((bVar6 = (byte)pcVar10->code, -1 < (char)bVar6 || ((bVar6 & 0x8f) != 0x80)) ||
              (cVar4 = type_is_class_or_template_parameter(pcVar10->base), cVar4 == '\0')))) {
            pcVar9 = right;
            type = right->type;
            iVar12 = type_is_class_or_enum(type);
            if ((((char)iVar12 != '\0') ||
                (iVar12 = type_is_template_type_parameter(type), (char)iVar12 != '\0')) ||
               (((type->code & 0xfff) == 0x802 ||
                (((bVar6 = (byte)type->code, uVar8 = report, pcVar10 = (c1_type *)report,
                  (char)bVar6 < '\0' && ((bVar6 & 0x8f) == 0x80)) &&
                 (cVar4 = type_is_class_or_template_parameter(type->base), uVar8 = report,
                 pcVar10 = (c1_type *)report, cVar4 != '\0')))))) {
              uVar8 = 0x2a5;
              pcVar10 = pcVar9->type;
            }
          }
          else {
            uVar8 = 0x2a4;
            pcVar10 = left->type;
          }
        }
        diag_error((short)uVar8,op & 0xff,pcVar10);
      }
      if (failed != (byte *)0x0) {
        *failed = 1;
      }
    }
    return (c1_node *)0x0;
  }
  uVar8 = ovl_rank_operator_candidates((c1_ovl_resolution *)&stack0x00000018);
  if ((char)uVar8 == '\0') {
    if ((frame_op == '1') && (frame_right == (c1_node *)0x0)) {
      return (c1_node *)0x0;
    }
    if (failed == (byte *)0x0) {
      return (c1_node *)0x0;
    }
    *failed = 1;
    return (c1_node *)0x0;
  }
  winner = (int *)ovl_unique_candidate((int)&stack0x00000018);
  failed_00 = failed;
  if ((winner == (int *)0x0) &&
     (winner = ovl_select_best_candidate(&stack0x00000018,failed,ovl_operator_no_best),
     winner == (int *)0x0)) {
    pcVar9 = expr_apply_overloaded_arrow_fragment(failed_00);
    return pcVar9;
  }
  pcVar13 = (c1_symbol *)*winner;
  if (((pcVar13 != (c1_symbol *)0x0) && ((*(byte *)((int)&pcVar13->tail + 9) & 0x40) != 0)) &&
     ((pcVar13->flags2 & 4) == 0)) {
    iVar12 = (*g_idb->vtbl->idb_note_first_use)(g_idb);
    if (iVar12 == 0) {
      diag_fatal(0x49,"..\\Cxx\\biops.c",0x2ca);
    }
    tmpl_work_queue_add(pcVar13,(int *)winner[0xe]);
  }
  pcVar9 = expr_build_selected_operator(winner,left,right);
  if (op_byte != 'S') {
    return pcVar9;
  }
  if (pcVar9 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar13 = (c1_symbol *)pcVar9->type;
  uVar8 = type_classify_class_form((c1_type *)pcVar13,(int *)&left_cell);
  if ((uVar8 & 9) == 0) {
    if ((short)uVar8 == 4) {
      return pcVar9;
    }
    code_lo = pcVar13->kind;
    if (((char)code_lo < '\0') && ((code_lo & 0x8f) == 0x80)) {
      uVar7 = (*(c1_type **)&pcVar13->flags4)->code;
      if ((((char)uVar7 < '\0') && ((uVar7 = uVar7 & 0x8f, uVar7 == 0x86 || (uVar7 == 0x82)))) &&
         (((*(c1_type **)&pcVar13->flags4)->base->code & 0x200) != 0)) {
        return pcVar9;
      }
    }
    if ((char)report == '\0') goto LAB_104a3781;
    n = 0x347;
  }
  else {
    pcVar11 = class_lookup_member_set(g_current_scope,left_cell,g_name_operator_arrow,2,0);
    pcVar3 = g_arenas[5].cur;
    pcVar1 = chain_head;
    if (pcVar11 != (c1_symbol *)0x0) {
      while( true ) {
        if (pcVar1 == (c1_type_chain_cell *)0x0) {
          g_arenas[5].cur = g_arenas[5].cur + 8;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar3 != (c1_u8 *)0x0) {
            pcVar3[0] = '\0';
            pcVar3[1] = '\0';
            pcVar3[2] = '\0';
            pcVar3[3] = '\0';
            *(c1_symbol **)(pcVar3 + 4) = pcVar13;
            if (chain_tail != (c1_type_chain_cell *)0x0) {
              chain_tail->next = (c1_type_chain_cell *)pcVar3;
            }
          }
          op_slot = CONCAT31(op_slot._1_3_,0x53);
          pcVar9 = (c1_node *)(*(code *)(undefined *)0x104a3496)();
          return pcVar9;
        }
        if (pcVar13 == (c1_symbol *)pcVar1->type) break;
        pcVar1 = pcVar1->next;
      }
      if ((char)report != '\0') {
        cVar4 = (char)*(c1_u16 *)&pcVar13->kind;
        while (cVar4 < '\0') {
          pcVar13 = *(c1_symbol **)&pcVar13->flags4;
          cVar4 = (char)*(c1_u16 *)&pcVar13->kind;
        }
        uVar7._0_1_ = pcVar13->kind;
        uVar7._1_1_ = pcVar13->flags1;
        if ((uVar7 & 0x300) == 0) {
          chain_class_4 = (c1_symbol *)0x0;
        }
        else {
          chain_class_4 = ((c1_type_extra *)&pcVar13->name)->cls;
        }
        diag_error(0x332,chain_class_4);
        if ((chain_head == (c1_type_chain_cell *)0x0) ||
           (chain_head->next == (c1_type_chain_cell *)0x0)) {
          diag_warning(3,0x118,chain_class_4);
        }
        else {
          pcVar10 = chain_head->type;
          cVar4 = (char)pcVar10->code;
          while (cVar4 < '\0') {
            pcVar10 = pcVar10->base;
            cVar4 = (char)pcVar10->code;
          }
          if ((pcVar10->code & 0x300) == 0) {
            chain_class_3 = (c1_symbol *)0x0;
          }
          else {
            chain_class_3 = (pcVar10->extra).cls;
          }
          diag_warning(3,0x119,chain_class_3);
          pcVar1 = chain_head->next;
          pcVar2 = pcVar1->next;
          while (pcVar2 != (c1_type_chain_cell *)0x0) {
            pcVar10 = pcVar1->type;
            cVar4 = (char)pcVar10->code;
            while (cVar4 < '\0') {
              pcVar10 = pcVar10->base;
              cVar4 = (char)pcVar10->code;
            }
            if ((pcVar10->code & 0x300) == 0) {
              chain_class_2 = (c1_symbol *)0x0;
            }
            else {
              chain_class_2 = (pcVar10->extra).cls;
            }
            diag_warning(3,0x11a,chain_class_2);
            pcVar1 = pcVar1->next;
            pcVar2 = pcVar1->next;
          }
          pcVar10 = pcVar1->type;
          cVar4 = (char)pcVar10->code;
          while (cVar4 < '\0') {
            pcVar10 = pcVar10->base;
            cVar4 = (char)pcVar10->code;
          }
          iVar12 = type_is_class_or_enum(pcVar10);
          if ((char)iVar12 == '\0') {
            chain_class = (c1_symbol *)0x0;
          }
          else {
            chain_class = (pcVar10->extra).cls;
          }
          diag_warning(3,0x11b,chain_class);
        }
      }
      goto LAB_104a3781;
    }
    if ((char)report == '\0') goto LAB_104a3781;
    n = 0x333;
    pcVar13 = left_cell;
  }
  diag_error(n,pcVar13);
LAB_104a3781:
  if (failed != (byte *)0x0) {
    *failed = 1;
  }
  return pcVar9;
}

