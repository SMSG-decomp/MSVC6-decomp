void __fastcall coalesce_temp_copies(c2_function *fn)

{
  c2_symbol **ppcVar1;
  uint8_t *puVar2;
  uint16_t a;
  c2_tuple *pcVar3;
  int iVar4;
  c2_symbol *pcVar5;
  c2_tuple *pcVar6;
  c2_operand *pcVar7;
  uint16_t uVar8;
  c2_tuple *pcVar9;
  c2_symbol *sym;
  c2_symbol *temp;
  c2_list_cell *def_cell;
  c2_operand *local_10;
  c2_symbol **temp_link;
  c2_tuple *end_tuple;
  uint local_4;
  c2_list_cell *cell;
  c2_list_cell *ref_cell;
  
  temp = g_touched_temp_list;
  end_tuple = (c2_tuple *)fn;
  if (g_touched_temp_list != (c2_symbol *)0xffffffff) {
    do {
      g_touched_temp_list = (c2_symbol *)0xffffffff;
      if (temp == (c2_symbol *)0xffffffff) break;
      do {
        sym = temp->order_next;
        ppcVar1 = &temp->order_next;
        for (cell = (c2_list_cell *)temp->visit_stamp; temp_link = ppcVar1,
            cell != (c2_list_cell *)0x0; cell = cell->next) {
          if (((cell->u04).sym)->order_next != (c2_symbol *)0x0) {
            *ppcVar1 = g_touched_temp_list;
            g_touched_temp_list = temp;
            goto LAB_10727f27;
          }
        }
        ref_cell = temp->uses;
        if (((((ref_cell != (c2_list_cell *)0x0) && (ref_cell->next == (c2_list_cell *)0x0)) &&
             (temp->defs != (c2_list_cell *)0x0)) &&
            ((pcVar9 = (ref_cell->u04).tuple, pcVar9 != (c2_tuple *)0x0 &&
             (pcVar9->dst->kind == '\x02')))) &&
           ((pcVar9->dst->sym->def == (c2_tuple *)0x0 &&
            (iVar4 = node_has_side_effects((c2_node *)pcVar9), iVar4 == 0)))) {
          def_cell = temp->defs;
          uVar8 = pcVar9->type;
          if (def_cell != (c2_list_cell *)0x0) {
LAB_10727f8f:
            pcVar3 = (def_cell->u04).tuple;
            iVar4 = tuple_reaches_in_straight_line(pcVar9,pcVar3);
            if (((iVar4 == 0) ||
                (iVar4 = operand_referenced_between(pcVar3->next,pcVar9->prev,pcVar9->dst),
                iVar4 != 0)) ||
               (iVar4 = operand_referenced_between(pcVar3->next,pcVar9->prev,pcVar9->src),
               iVar4 != 0)) goto LAB_10727f0c;
            a = pcVar3->dst->type;
            iVar4 = types_compatible(a,uVar8);
            if (iVar4 == 0) {
              switch(pcVar3->src->kind) {
              case '\x01':
              case '\x02':
              case '\x06':
              case '\a':
                goto switchD_10728053_caseD_1;
              default:
                goto switchD_10728053_caseD_3;
              }
            }
            goto LAB_10727fe5;
          }
LAB_10727ff7:
          for (ref_cell = temp->defs; ref_cell != (c2_list_cell *)0x0; ref_cell = ref_cell->next) {
            pcVar3 = (ref_cell->u04).tuple;
            tuple_replace_dst(pcVar3,pcVar3->dst,pcVar9->dst);
            pcVar7 = pcVar3->src;
            switch(pcVar7->kind) {
            case '\0':
              halt_baddata();
            case '\x01':
            case '\x02':
              pcVar5 = symbol_get_part(pcVar7->sym,uVar8,0,0);
              pcVar3->src->sym = pcVar5;
              break;
            case '\a':
              constant_convert(CONCAT22((short)((uint)ppcVar1 >> 0x10),uVar8),pcVar7);
            }
            pcVar3->src->type = uVar8;
            pcVar3->type = uVar8;
          }
          tuple_unlink_free(pcVar9);
        }
LAB_10727f0c:
        *temp_link = (c2_symbol *)0x0;
        temp->uses = (c2_list_cell *)0x0;
        temp->defs = (c2_list_cell *)0x0;
        temp->visit_stamp = 0;
LAB_10727f27:
        temp = sym;
      } while (sym != (c2_symbol *)0xffffffff);
      temp = g_touched_temp_list;
    } while (g_touched_temp_list != (c2_symbol *)0xffffffff);
    puVar2 = &end_tuple->kind;
    end_tuple = *(c2_tuple **)((*(int **)puVar2)[1] + 0x20);
    pcVar9 = (c2_tuple *)**(int **)(**(int **)puVar2 + 0x1c);
    if (pcVar9 != end_tuple) {
      do {
        pcVar3 = pcVar9->next;
        if ((pcVar9->flags & 0x40) != 0) {
          pcVar9->flags = pcVar9->flags & 0xbf;
          if (((1 << (pcVar9->dst->kind & 0x1f) & 6U) == 0) ||
             (sym = pcVar9->dst->sym, sym->def == (c2_tuple *)0x0)) {
            if ((1 << (pcVar9->src->kind & 0x1f) & 6U) != 0) {
              pcVar5 = pcVar9->src->sym;
              pcVar6 = pcVar5->def;
              if ((pcVar6 != (c2_tuple *)0x0) && (pcVar6->kind != '\x0e')) {
                pcVar7 = pcVar6->dst;
                sym = pcVar7->sym;
                if (sym == pcVar5) {
                  uVar8 = pcVar7->type;
                  pcVar7 = tuple_replace_dst(pcVar6,pcVar7,pcVar9->dst);
                  goto LAB_1072817e;
                }
              }
            }
          }
          else {
            pcVar6 = find_next_use_of_dst(pcVar9,&local_10);
            if (sym == local_10->sym) {
              uVar8 = local_10->type;
              pcVar7 = tuple_replace_src(pcVar6,local_10,pcVar9->src);
              local_10 = pcVar7;
LAB_1072817e:
              pcVar7->type = uVar8;
              tuple_unlink_free(pcVar9);
              symbol_free_chain(sym);
            }
          }
        }
        pcVar9 = pcVar3;
      } while (pcVar3 != end_tuple);
    }
    reset_list_node_pool();
  }
  return;
switchD_10728053_caseD_1:
  if (a != uVar8) {
    if ((1 << (byte)(a >> 0xc) & 0xeU) == 0) {
      if (((a & 0xf000) != 0x5000) ||
         (local_4 = (uint)((uVar8 & 0xfff) <= (a & 0xfff)), local_4 == 0))
      goto switchD_10728053_caseD_3;
    }
    else if ((((1 << (byte)(uVar8 >> 0xc) & 0xeU) == 0) && ((uVar8 & 0xf000) != 0x5000)) ||
            ((a & 0xfff) < (uVar8 & 0xfff))) {
switchD_10728053_caseD_3:
      goto LAB_10727f0c;
    }
  }
LAB_10727fe5:
  def_cell = def_cell->next;
  if (def_cell == (c2_list_cell *)0x0) goto LAB_10727ff7;
  goto LAB_10727f8f;
}

