void __fastcall
warn_uninit_scan_uses
          (c2_function *fn,c2_block *b,c2_bitset *cands,c2_bitset *remaining,int check_paths)

{
  ushort uVar1;
  c2_operand *op;
  uint32_t uVar2;
  c2_symbol *pcVar3;
  uint32_t uVar4;
  int iVar5;
  char *pcVar6;
  c2_tuple *local_c;
  
  local_c = b->head->next;
  if (local_c != b->end) {
    do {
      if (((local_c->flags & 1) != 0) && (local_c->flags12 != '\0')) {
        uVar1 = local_c->line;
        if (uVar1 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar1;
          g_cur_line = uVar1;
        }
        for (op = local_c->src; op != (c2_operand *)0x0; op = op->next) {
          if (((op->kind == '\x02') && (uVar2 = (op->sym->u30).local_number, uVar2 != 0)) &&
             (uVar4 = bitset_test(cands,uVar2), uVar4 != 0)) {
            if ((((check_paths == 0) || (b->loop == (c2_loop *)0x0)) ||
                (((b->loop->flags & 1) != 0 ||
                 (iVar5 = warn_uninit_path_initialises(fn,b,uVar2), iVar5 == 0)))) &&
               (iVar5 = tuple_reads_shifted_self(local_c,op), iVar5 == 0)) {
              pcVar6 = fe_symbol_name(g_uninit_local_symbols[uVar2]->storage->fe,1);
              warning(1,700,pcVar6);
              for (pcVar3 = g_uninit_local_symbols[uVar2]->storage; pcVar3 != (c2_symbol *)0x0;
                  pcVar3 = pcVar3->part_next) {
                uVar2 = (pcVar3->u30).local_number;
                bitset_clear(cands,uVar2);
                bitset_clear(remaining,uVar2);
              }
            }
            else {
              bitset_clear(cands,uVar2);
            }
          }
        }
        if (cands->chunks == (c2_bitset_chunk *)0x0) {
          return;
        }
      }
      local_c = local_c->next;
    } while (local_c != b->end);
  }
  return;
}

