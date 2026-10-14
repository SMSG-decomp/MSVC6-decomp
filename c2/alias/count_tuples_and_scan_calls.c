int __fastcall count_tuples_and_scan_calls(c2_tuple *first)

{
  c2_seh_try_scope *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  bool bVar4;
  c2_tuple *first_00;
  c2_fe_symbol *pcVar5;
  int iVar6;
  int mark_destinations;
  int mark_address_sources;
  int local_4;
  
  bVar4 = true;
  iVar6 = 0;
  local_4 = 1;
  if (first != (c2_tuple *)0x0) {
    do {
      if ((first->flags & 1) == 0) {
        if (((first->kind == '\x16') && (first->op == 0x1b4)) && ((first->u14).arg != (void *)0x0))
        {
          local_4 = local_4 + 1;
        }
      }
      else {
        iVar6 = iVar6 + 1;
        switch(first->op) {
        case 0x17d:
          break;
        case 0x184:
          pcVar5 = call_target_function_symbol(first);
          if ((pcVar5 == (c2_fe_symbol *)0x0) || ((pcVar5->attrs & 0x800) == 0)) {
            bVar4 = false;
          }
        default:
          for (pcVar2 = first->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if (pcVar2->kind == '\x03') {
              for (pcVar3 = pcVar2->sym->storage; pcVar3 != (c2_symbol *)0x0;
                  pcVar3 = pcVar3->part_next) {
                pcVar3->flags5 = pcVar3->flags5 | 2;
              }
            }
          }
          break;
        case 0x191:
          mark_inline_asm_operand_symbols((first->u20).default_label);
          break;
        case 0x192:
          if (g_opt_basic == 0) {
            pcVar1 = (first->u20).seh_scope;
            if (pcVar1->kind == 2) {
              mark_region_symbols_memory_resident
                        (first,(pcVar1->continuation_label->u32).label_tuple,1,0);
            }
            else {
              mark_region_symbols_memory_resident
                        (first,(pcVar1->handler_label->u32).label_tuple,1,0);
            }
          }
          break;
        case 0x1a0:
          mark_address_sources = 1;
          mark_destinations = 1;
          first_00 = eh_funclet_entry_tuple(first);
          mark_region_symbols_memory_resident
                    (first_00,(c2_tuple *)0x0,mark_destinations,mark_address_sources);
          break;
        case 0x1a4:
          if (g_opt_eh_enabled == 0) {
            mark_region_symbols_memory_resident
                      (first,(((first->u20).eh_try)->try_block->catches->label->u32).label_tuple,1,0
                      );
          }
        }
      }
      first = first->next;
    } while (first != (c2_tuple *)0x0);
    if (!bVar4) goto LAB_1072e28c;
  }
  g_cur_func_sym->attrs = g_cur_func_sym->attrs | 0x800;
LAB_1072e28c:
  if (10000 < iVar6) {
    g_opt_assume_no_alias = 0;
    g_alias_analysis_overflow = 1;
    return 1;
  }
  return local_4;
}

