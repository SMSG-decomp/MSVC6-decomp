c2_list_cell * __fastcall emit_collect_symbol_refs(c2_function *fn)

{
  char cVar1;
  ushort uVar2;
  c2_operand *pcVar3;
  c2_list_cell *pcVar4;
  c2_list_cell *pcVar5;
  c2_tuple *t;
  int iVar6;
  c2_fe_symbol *pcVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  c2_fe_symbol *sym;
  c2_tuple *pcVar11;
  c2_fe_symbol *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char ordinal_suffix [100];
  
  if (fn == (c2_function *)0x0) {
    sym = (c2_fe_symbol *)0x0;
  }
  else {
    sym = fn->fsym;
    for (pcVar11 = fn->cfg->first->head; pcVar11 != (c2_tuple *)0x0; pcVar11 = pcVar11->next) {
      uVar2 = pcVar11->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      t = pcVar11;
      switch(pcVar11->kind) {
      case '\f':
      case '\r':
      case '\x0e':
      case '\x0f':
      case '\x10':
      case '\x11':
      case '\x12':
      case '\x13':
      case '\x14':
      case '\x15':
        iVar6 = 2;
        do {
          if (iVar6 == 2) {
            pcVar3 = pcVar11->dst;
          }
          else {
            pcVar3 = pcVar11->src;
          }
          for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            switch(pcVar3->kind) {
            case '\x02':
            case '\x03':
              pcVar12 = pcVar3->sym->storage->fe;
LAB_10741048:
              if (((pcVar12 != (c2_fe_symbol *)0x0) &&
                  (note_symbol_referenced(pcVar12), pcVar12->cls == '\x04')) &&
                 (((pcVar12->storage & 0x4000) != 0 && ((pcVar12->storage & 0x1000) == 0)))) {
                pcVar12->fn_flags = pcVar12->fn_flags | 0x20;
              }
              break;
            case '\x04':
              pcVar12 = (c2_fe_symbol *)pcVar3->sym;
              if (((pcVar11->op == 0xbb) || (pcVar12->cls != '\x03')) || (pcVar3->op != 0x154))
              goto LAB_10741048;
              break;
            case '\x05':
            case '\x06':
              if (pcVar3->base_sym != (c2_symbol *)0x0) {
                pcVar12 = pcVar3->base_sym->storage->fe;
                goto LAB_10741048;
              }
            }
          }
          iVar6 = iVar6 + -1;
        } while (0 < iVar6);
        break;
      case '\x16':
        if (pcVar11->op == 0x1bc) {
          pcVar12 = (c2_fe_symbol *)(pcVar11->u14).fn;
          if ((pcVar12->u32).label_tuple == (c2_tuple *)0x0) {
            t = tuple_new_label(pcVar12);
          }
          else {
            pcVar7 = fe_symbol_copy(pcVar12,1);
            pcVar12->refcount = pcVar12->refcount + 1;
            pcVar7->refcount = 0;
            (pcVar7->u32).label_tuple = (c2_tuple *)0x0;
            ordinal_suffix[0] = '_';
            iVar6 = format_integer(pcVar12->refcount,ordinal_suffix + 1,10);
            pcVar13 = pcVar12->name;
            uVar9 = 0xffffffff;
            pcVar8 = pcVar13;
            do {
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              cVar1 = *pcVar8;
              pcVar8 = pcVar8 + 1;
            } while (cVar1 != '\0');
            pcVar8 = arena_alloc(1,~uVar9 + iVar6);
            uVar9 = 0xffffffff;
            pcVar7->name = pcVar8;
            do {
              pcVar14 = pcVar13;
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              pcVar14 = pcVar13 + 1;
              cVar1 = *pcVar13;
              pcVar13 = pcVar14;
            } while (cVar1 != '\0');
            uVar9 = ~uVar9;
            pcVar13 = pcVar14 + -uVar9;
            for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined4 *)pcVar8 = *(undefined4 *)pcVar13;
              pcVar13 = pcVar13 + 4;
              pcVar8 = pcVar8 + 4;
            }
            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              *pcVar8 = *pcVar13;
              pcVar13 = pcVar13 + 1;
              pcVar8 = pcVar8 + 1;
            }
            uVar9 = 0xffffffff;
            pcVar13 = ordinal_suffix;
            do {
              pcVar8 = pcVar13;
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              pcVar8 = pcVar13 + 1;
              cVar1 = *pcVar13;
              pcVar13 = pcVar8;
            } while (cVar1 != '\0');
            uVar9 = ~uVar9;
            iVar6 = -1;
            pcVar13 = pcVar7->name;
            do {
              pcVar14 = pcVar13;
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              pcVar14 = pcVar13 + 1;
              cVar1 = *pcVar13;
              pcVar13 = pcVar14;
            } while (cVar1 != '\0');
            pcVar13 = pcVar8 + -uVar9;
            pcVar8 = pcVar14 + -1;
            for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined4 *)pcVar8 = *(undefined4 *)pcVar13;
              pcVar13 = pcVar13 + 4;
              pcVar8 = pcVar8 + 4;
            }
            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              *pcVar8 = *pcVar13;
              pcVar13 = pcVar13 + 1;
              pcVar8 = pcVar8 + 1;
            }
            t = tuple_new_label(pcVar7);
          }
          tuple_insert_after(pcVar11,t);
          tuple_unlink_free(pcVar11);
          goto switchD_10740ffd_caseD_1a;
        }
        break;
      case '\x17':
        note_symbol_referenced(((pcVar11->u14).fn)->fsym);
        break;
      case '\x1a':
switchD_10740ffd_caseD_1a:
        pcVar11 = t;
        if (g_opt_debug_info == 0) {
          if ((*(byte *)&((c2_fe_symbol *)t->src)->u3e & 1) != 0) {
            note_symbol_referenced((c2_fe_symbol *)t->src);
          }
        }
        else {
          pcVar12 = (c2_fe_symbol *)t->src;
          if (pcVar12->role != '\0') {
            if ((pcVar12->role != '\x02') && ((*(byte *)&pcVar12->u3e & 1) == 0)) break;
            symbol_ref_list_add(&fn->cv_scopes->symbols,pcVar12);
          }
          note_symbol_referenced((c2_fe_symbol *)t->src);
        }
      }
    }
  }
  pcVar5 = move_zero_initialized_data_to_bss();
  for (pcVar4 = pcVar5; pcVar4 != (c2_list_cell *)0x0; pcVar4 = pcVar4->next) {
    if ((sym != (c2_fe_symbol *)0x0) && ((g_opt_incremental != 0 || ((sym->attrs & 0x20) != 0)))) {
      pcVar12 = (pcVar4->u04).fe;
      iVar6 = scope_contains_id(pcVar12->id);
      if (iVar6 != 0) {
        pcVar7 = coff_select_data_section(sym,pcVar12);
        pcVar12->section_id = pcVar7->id;
      }
    }
    fe_symbol_assign_frame((pcVar4->u04).fe);
  }
  return pcVar5;
}

