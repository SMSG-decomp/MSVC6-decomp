c1_node * __cdecl
expr_apply_overloaded_operator
          (c1_u8 op,c1_node *left,c1_node *right,uint flag4,uint report,byte *failed)

{
  c1_type_chain_cell *pcVar1;
  c1_type *type;
  ushort uVar5;
  char cVar2;
  bool bVar3;
  byte bVar4;
  uint uVar6;
  int *winner;
  c1_node *pcVar7;
  c1_type *pcVar8;
  c1_symbol *pcVar9;
  c1_node *pcVar10;
  c1_u32 note_cls_2;
  int iVar11;
  c1_u32 note_cls_4;
  c1_u32 note_cls;
  c1_u8 cVar12;
  c1_type_chain_cell *pcVar13;
  c1_symbol *pcVar14;
  c1_u32 note_cls_3;
  undefined3 in_stack_00000005;
  short n;
  uint report_00;
  byte *pbVar15;
  c1_type_chain_cell *chain_tail;
  c1_type_chain_cell *chain_head;
  byte res [60];
  c1_u8 cStack_c;
  c1_u8 cStack_b;
  c1_ovl_extra cStack_4;
  undefined1 type_code_lo;
  
  chain_tail = (c1_type_chain_cell *)0x0;
  chain_head = (c1_type_chain_cell *)0x0;
  pcVar7 = left;
  cVar12 = op;
  while( true ) {
    switch(_op & 0xff) {
    case 0x36:
    case 0x50:
    case 0x56:
    case 0x76:
    case 0x8c:
    case 0x8d:
    case 0x92:
      return (c1_node *)0x0;
    case 0x38:
    case 0x40:
      if (((g_ms_extensions != '\0') && ((char)flag4 != '\0')) && ((char)report != '\0')) {
        pbVar15 = (byte *)0x0;
        report_00 = 0;
        uVar6 = 1;
        pcVar10 = tree_copy_to_arena(g_tree_zero_constant,g_expr_arena_index);
        pcVar10 = expr_apply_overloaded_operator((byte)_op,pcVar7,pcVar10,uVar6,report_00,pbVar15);
        if (pcVar10 != (c1_node *)0x0) {
          return pcVar10;
        }
        pcVar10 = expr_apply_overloaded_operator((cVar12 == '@') + 'T',pcVar7,right,1,0,(byte *)0x0)
        ;
        if (pcVar10 != (c1_node *)0x0) {
          pcVar8 = pcVar7->type;
          cVar2 = (char)pcVar8->code;
          if (cVar12 != '@') {
            while (cVar2 < '\0') {
              pcVar8 = pcVar8->base;
              cVar2 = (char)pcVar8->code;
            }
            if ((pcVar8->code & 0x300) == 0) {
              pcVar14 = (c1_symbol *)0x0;
            }
            else {
              pcVar14 = (pcVar8->extra).cls;
            }
            diag_warning(1,0x26d,pcVar14);
            return pcVar10;
          }
          while (cVar2 < '\0') {
            pcVar8 = pcVar8->base;
            cVar2 = (char)pcVar8->code;
          }
          if ((pcVar8->code & 0x300) == 0) {
            diag_warning(1,0x26c,0);
            return pcVar10;
          }
          diag_warning(1,0x26c,(pcVar8->extra).cls);
          return pcVar10;
        }
      }
      right = tree_copy_to_arena(g_tree_zero_constant,g_expr_arena_index);
      break;
    case 0x53:
      if ((pcVar7->type->code & 0x200) == 0) {
        pcVar14 = (c1_symbol *)0x0;
      }
      else {
        pcVar14 = (pcVar7->type->extra).cls;
      }
      pcVar9 = class_lookup_member_set(g_current_scope,pcVar14,g_name_operator_arrow,2,0);
      if (pcVar9 == (c1_symbol *)0x0) {
        if ((char)report != '\0') {
          diag_error(0x333,pcVar14);
        }
        if (failed != (byte *)0x0) {
          *failed = 1;
        }
        return pcVar7;
      }
      break;
    case 0x54:
    case 0x55:
      right = (c1_node *)0x0;
    }
    pcVar10 = right;
    if ((char)flag4 == '\0') {
      pcVar8 = (c1_type *)0x0;
    }
    else {
      pcVar8 = pcVar7->type;
    }
    ovl_collect_operator_candidates((c1_ovl_resolution *)res,_op,pcVar7,right,pcVar8);
    if ((cStack_c != '\0') ||
       (cVar2 = ovl_prune_candidates_by_arity(res,(void *)0x0), cVar2 == '\0')) {
      bVar3 = expr_builtin_operator_valid_for_class
                        ((byte)_op,(pcVar10 != (c1_node *)0x0) + '\x01',flag4 & 0xff);
      if (bVar3) {
        return (c1_node *)0x0;
      }
      if ((char)report != '\0') {
        if (pcVar10 == (c1_node *)0x0) {
          uVar6 = 0x2a3;
          pcVar8 = pcVar7->type;
        }
        else {
          pcVar8 = pcVar7->type;
          iVar11 = type_is_class_or_enum(pcVar8);
          if ((((char)iVar11 == '\0') &&
              (iVar11 = type_is_template_type_parameter(pcVar8), (char)iVar11 == '\0')) &&
             (((pcVar8->code & 0xfff) != 0x802 &&
              (((bVar4 = (byte)pcVar8->code, -1 < (char)bVar4 || ((bVar4 & 0x8f) != 0x80)) ||
               (cVar2 = type_is_class_or_template_parameter(pcVar8->base), cVar2 == '\0')))))) {
            pcVar7 = right;
            type = right->type;
            iVar11 = type_is_class_or_enum(type);
            if ((((char)iVar11 != '\0') ||
                (iVar11 = type_is_template_type_parameter(type), (char)iVar11 != '\0')) ||
               (((type->code & 0xfff) == 0x802 ||
                (((bVar4 = (byte)type->code, uVar6 = report, pcVar8 = (c1_type *)report,
                  (char)bVar4 < '\0' && ((bVar4 & 0x8f) == 0x80)) &&
                 (cVar2 = type_is_class_or_template_parameter(type->base), uVar6 = report,
                 pcVar8 = (c1_type *)report, cVar2 != '\0')))))) {
              uVar6 = 0x2a5;
              pcVar8 = pcVar7->type;
            }
          }
          else {
            uVar6 = 0x2a4;
            pcVar8 = pcVar7->type;
          }
        }
        diag_error((short)uVar6,_op & 0xff,pcVar8);
      }
      if (failed == (byte *)0x0) {
        return (c1_node *)0x0;
      }
      *failed = 1;
      return (c1_node *)0x0;
    }
    uVar6 = ovl_rank_operator_candidates((c1_ovl_resolution *)res);
    if ((char)uVar6 == '\0') {
      if ((cStack_b == '1') && (cStack_4.right == (c1_node *)0x0)) {
        return (c1_node *)0x0;
      }
      if (failed == (byte *)0x0) {
        return (c1_node *)0x0;
      }
      *failed = 1;
      return (c1_node *)0x0;
    }
    winner = (int *)ovl_unique_candidate((int)res);
    pbVar15 = failed;
    if ((winner == (int *)0x0) &&
       (winner = ovl_select_best_candidate(res,failed,ovl_operator_no_best), winner == (int *)0x0))
    {
      pcVar7 = expr_apply_overloaded_arrow_fragment(pbVar15);
      return pcVar7;
    }
    pcVar14 = (c1_symbol *)*winner;
    if (((pcVar14 != (c1_symbol *)0x0) && ((*(byte *)((int)&pcVar14->tail + 9) & 0x40) != 0)) &&
       ((pcVar14->flags2 & 4) == 0)) {
      iVar11 = (*g_idb->vtbl->idb_note_first_use)(g_idb);
      if (iVar11 == 0) {
        diag_fatal(0x49,"..\\Cxx\\biops.c",0x2ca);
      }
      tmpl_work_queue_add(pcVar14,(int *)winner[0xe]);
    }
    pcVar7 = expr_build_selected_operator(winner,pcVar7,right);
    if (cVar12 != 'S') {
      return pcVar7;
    }
    if (pcVar7 == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
    pcVar10 = (c1_node *)pcVar7->type;
    uVar6 = type_classify_class_form((c1_type *)pcVar10,(int *)&left);
    if ((uVar6 & 9) == 0) break;
    note_cls_2 = (c1_u32)class_lookup_member_set
                                   (g_current_scope,(c1_symbol *)left,g_name_operator_arrow,2,0);
    pcVar13 = (c1_type_chain_cell *)g_arenas[5].cur;
    pcVar1 = chain_head;
    if (note_cls_2 == 0) {
      if ((char)report != '\0') {
        n = 0x333;
        pcVar10 = left;
        goto LAB_104a37cf;
      }
      goto LAB_104a3781;
    }
    for (; pcVar1 != (c1_type_chain_cell *)0x0; pcVar1 = pcVar1->next) {
      if (pcVar10 == (c1_node *)pcVar1->type) {
        if ((char)report != '\0') {
          cVar2 = (char)*(c1_u16 *)&pcVar10->op;
          while (cVar2 < '\0') {
            pcVar10 = (c1_node *)pcVar10->type;
            cVar2 = (char)*(c1_u16 *)&pcVar10->op;
          }
          uVar5._0_1_ = pcVar10->op;
          uVar5._1_1_ = pcVar10->kind;
          if ((uVar5 & 0x300) == 0) {
            pcVar14 = (c1_symbol *)0x0;
          }
          else {
            pcVar14 = ((c1_type_extra *)&pcVar10->link)->cls;
          }
          diag_error(0x332,pcVar14);
          if ((chain_head == (c1_type_chain_cell *)0x0) ||
             (chain_head->next == (c1_type_chain_cell *)0x0)) {
            diag_warning(3,0x118,pcVar14);
          }
          else {
            pcVar8 = chain_head->type;
            cVar2 = (char)pcVar8->code;
            while (cVar2 < '\0') {
              pcVar8 = pcVar8->base;
              cVar2 = (char)pcVar8->code;
            }
            if ((pcVar8->code & 0x300) == 0) {
              note_cls_4 = 0;
            }
            else {
              note_cls_4 = (c1_u32)(pcVar8->extra).cls;
            }
            diag_warning(3,0x119,note_cls_4);
            pcVar1 = chain_head->next;
            pcVar13 = pcVar1->next;
            while (pcVar13 != (c1_type_chain_cell *)0x0) {
              pcVar8 = pcVar1->type;
              cVar2 = (char)pcVar8->code;
              while (cVar2 < '\0') {
                pcVar8 = pcVar8->base;
                cVar2 = (char)pcVar8->code;
              }
              if ((pcVar8->code & 0x300) == 0) {
                note_cls = 0;
              }
              else {
                note_cls = (c1_u32)(pcVar8->extra).cls;
              }
              diag_warning(3,0x11a,note_cls);
              pcVar1 = pcVar1->next;
              pcVar13 = pcVar1->next;
            }
            pcVar8 = pcVar1->type;
            cVar2 = (char)pcVar8->code;
            while (cVar2 < '\0') {
              pcVar8 = pcVar8->base;
              cVar2 = (char)pcVar8->code;
            }
            iVar11 = type_is_class_or_enum(pcVar8);
            if ((char)iVar11 == '\0') {
              note_cls_3 = 0;
            }
            else {
              note_cls_3 = (c1_u32)(pcVar8->extra).cls;
            }
            diag_warning(3,0x11b,note_cls_3);
          }
        }
        goto LAB_104a3781;
      }
    }
    g_arenas[5].cur = g_arenas[5].cur + 8;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar13 == (c1_type_chain_cell *)0x0) {
      pcVar13 = (c1_type_chain_cell *)0x0;
    }
    else {
      *(c1_u8 *)((int)pcVar13 + 0) = '\0';
      *(c1_u8 *)((int)pcVar13 + 1) = '\0';
      *(c1_u8 *)((int)pcVar13 + 2) = '\0';
      *(c1_u8 *)((int)pcVar13 + 3) = '\0';
      *(c1_node **)((int)pcVar13 + 4) = pcVar10;
      if (chain_tail != (c1_type_chain_cell *)0x0) {
        chain_tail->next = pcVar13;
      }
    }
    if (chain_head == (c1_type_chain_cell *)0x0) {
      chain_head = pcVar13;
    }
    cVar12 = 'S';
    _op = CONCAT31(in_stack_00000005,0x53);
    chain_tail = pcVar13;
  }
  if ((short)uVar6 == 4) {
    return pcVar7;
  }
  type_code_lo = pcVar10->op;
  if (((char)type_code_lo < '\0') && ((type_code_lo & 0x8f) == 0x80)) {
    uVar5 = pcVar10->type->code;
    if ((((char)uVar5 < '\0') && ((uVar5 = uVar5 & 0x8f, uVar5 == 0x86 || (uVar5 == 0x82)))) &&
       ((pcVar10->type->base->code & 0x200) != 0)) {
      return pcVar7;
    }
  }
  if ((char)report != '\0') {
    n = 0x347;
LAB_104a37cf:
    diag_error(n,pcVar10);
  }
LAB_104a3781:
  if (failed != (byte *)0x0) {
    *failed = 1;
  }
  return pcVar7;
}

