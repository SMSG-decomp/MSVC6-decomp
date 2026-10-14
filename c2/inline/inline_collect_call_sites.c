c2_list_cell * __fastcall inline_collect_call_sites(c2_function *fn,int *count,int flag)

{
  ushort uVar1;
  c2_cfg *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_tuple *t;
  c2_symbol *pcVar6;
  uint32_t uVar7;
  c2_list_cell *pcVar8;
  c2_tuple *t_00;
  c2_fe_symbol *f;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  c2_list_cell *site;
  c2_tuple *pcVar12;
  c2_fe_symbol *pcVar13;
  uint8_t uVar14;
  c2_list_cell *local_20;
  c2_list_cell *local_1c;
  c2_operand *local_8;
  c2_operand *local_4;
  
  pcVar2 = fn->cfg;
  *count = 0;
  local_1c = (c2_list_cell *)0x0;
  uVar14 = '\0';
  local_20 = (c2_list_cell *)0x0;
  pcVar8 = (c2_list_cell *)0x0;
  pcVar4 = pcVar2->first->head;
joined_r0x1072db37:
  do {
    while( true ) {
      do {
        while( true ) {
          while( true ) {
            t_00 = pcVar4;
            if (t_00 == (c2_tuple *)0x0) {
              return pcVar8;
            }
            pcVar4 = t_00->next;
            if ((t_00->flags & 1) != 0) break;
            if (t_00->kind == '\x16') {
              if (t_00->op == 0x1b8) {
                local_1c = (t_00->u14).arg;
                tuple_unlink_free(t_00);
              }
            }
            else if ((t_00->kind == '\x1a') && (*(char *)&t_00->src[1].next == 'T')) {
              uVar7 = pcVar4->op;
              while (uVar7 != 0x1a7) {
                pcVar4 = pcVar4->next;
                uVar7 = pcVar4->op;
              }
              pcVar4 = pcVar4->next;
            }
          }
          pcVar5 = t_00->src;
          for (pcVar3 = pcVar5; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            if (((1 << (pcVar3->kind & 0x1f) & 6U) == 0) || (pcVar3->sym->def == (c2_tuple *)0x0)) {
              if ((pcVar3->kind == 3) && (t_00->op != 0x17d)) {
                for (pcVar6 = pcVar3->sym->storage; pcVar6 != (c2_symbol *)0x0;
                    pcVar6 = pcVar6->part_next) {
                  pcVar6->flags5 = pcVar6->flags5 | 2;
                }
              }
            }
            else {
              uVar14 = uVar14 + 0xff;
            }
          }
          pcVar3 = t_00->dst;
          t_00->flags12 = uVar14;
          for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            if (((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && (pcVar3->sym->def != (c2_tuple *)0x0)) {
              uVar14 = uVar14 + '\x01';
            }
          }
          if (t_00->kind == '\x0e') break;
          if (t_00->kind == '\x15') {
            inline_mark_address_taken((t_00->u20).default_label);
          }
        }
        uVar1 = t_00->line;
        if (uVar1 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar1;
          g_cur_line = uVar1;
        }
      } while (((((pcVar5->kind != '\x04') || (f = (c2_fe_symbol *)pcVar5->sym, f->cls != '\x04'))
                || ((f->storage & 0x4000) == 0)) &&
               (((pcVar5->kind != '\x02' || (f = pcVar5->sym->storage->fe, f == (c2_fe_symbol *)0x0)
                 ) || ((f->cls != '\x04' ||
                       (((f->storage & 0x4000) == 0 || ((f->storage & 0x1000) == 0)))))))) ||
              (f == (c2_fe_symbol *)0x0));
      if (((flag == 0) || ((f->fn_flags & 0x100) == 0)) &&
         ((((g_cur_function->flags & 0x18000) != 0 || ((f->fn_flags & 0x300) == 0)) &&
          (((g_opt_favor_speed != 0 || ((short)f->inline_size < g_inline_size_limit)) &&
           (iVar9 = function_is_inline_candidate(f,g_opt_global), iVar9 != 0)))))) break;
LAB_1072dcd5:
      if (((f->fn_flags & 0x2080) != 0) && ((f->fn_flags & 0x40) != 0)) {
        pcVar13 = f;
        if ((f->storage & 0x1000) != 0) {
          pcVar13 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)f);
        }
        pcVar10 = fe_symbol_name(pcVar13,1);
        warning(4,(-(uint)((f->fn_flags & 0x2000) != 0) & 4) + 0x2c6,pcVar10);
      }
    }
    for (pcVar3 = pcVar5->next; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
      if (((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && (t = pcVar3->sym->def, t != (c2_tuple *)0x0))
      {
        if (t->op == 0x16a) {
          pcVar5 = t->src;
          uVar11 = 1 << (pcVar5->kind & 0x1f) & 6;
          if ((uVar11 == 0) || (pcVar12 = pcVar5->sym->def, pcVar12 == (c2_tuple *)0x0)) {
            if ((uVar11 == 0) ||
               (((pcVar6 = pcVar5->sym, pcVar6->cls != '\x03' || (pcVar6->def != (c2_tuple *)0x0))
                || ((pcVar6->flags7 & 2) == 0)))) goto LAB_1072dd9e;
            pcVar12 = find_prev_def_of_operand(t,pcVar5,&local_8);
          }
          if ((pcVar12 != (c2_tuple *)0x0) &&
             (((pcVar12->kind == '\x12' && ((pcVar12->u20).intrinsic.id == 0xdf)) ||
              (pcVar12->op == 0x1aa)))) {
            if (((f->fn_flags & 0x2080) != 0) && ((f->fn_flags & 0x40) != 0)) {
              pcVar13 = f;
              if ((f->storage & 0x1000) != 0) {
                pcVar13 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)f);
              }
              pcVar10 = fe_symbol_name(pcVar13,1);
              warning(4,(-(uint)((f->fn_flags & 0x2000) != 0) & 4) + 0x2c6,pcVar10);
            }
            goto joined_r0x1072db37;
          }
        }
        else if (t->op == 0x15a) {
          pcVar5 = t->src;
          uVar11 = 1 << (pcVar5->kind & 0x1f) & 6;
          if ((uVar11 == 0) || (pcVar12 = pcVar5->sym->def, pcVar12 == (c2_tuple *)0x0)) {
            if ((uVar11 == 0) ||
               (((pcVar6 = pcVar5->sym, pcVar6->cls != '\x03' || (pcVar6->def != (c2_tuple *)0x0))
                || ((pcVar6->flags7 & 2) == 0)))) goto LAB_1072dd9e;
            pcVar12 = find_prev_def_of_operand(t,pcVar5,&local_4);
          }
          if (((pcVar12 != (c2_tuple *)0x0) && (pcVar12->kind == '\x12')) &&
             ((pcVar12->u20).intrinsic.id == 0x184)) goto LAB_1072dcd5;
        }
      }
LAB_1072dd9e:
    }
    uVar11 = f->fn_flags;
    if (((uVar11 & 0x10) == 0) || (((uint)local_1c & 0xf00) != 0)) {
      site = arena_alloc(4,0xc);
      (site->u04).tuple = t_00;
      site[1].next = local_1c;
      if (local_20 == (c2_list_cell *)0x0) {
        *count = *count + 1;
        pcVar8 = site;
        local_20 = site;
      }
      else {
        local_20->next = site;
        *count = *count + 1;
        local_20 = site;
      }
    }
    else if (((uVar11 & 0x2080) != 0) && ((uVar11 & 0x40) != 0)) {
      pcVar13 = f;
      if ((f->storage & 0x1000) != 0) {
        pcVar13 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)f);
      }
      pcVar10 = fe_symbol_name(pcVar13,1);
      warning(4,(-(uint)((f->fn_flags & 0x2000) != 0) & 4) + 0x2c6,pcVar10);
    }
  } while( true );
}

