void __fastcall hash_scope_emit_il(c1xx_hash_scope *scope)

{
  c1_sym_link *pcVar1;
  bool bVar2;
  c1_sym_link *pcVar3;
  char cVar4;
  c1_sym_link *pcVar5;
  uint uVar6;
  c1_sym_link *pcStack_1c;
  c1_sym_link *pcStack_18;
  c1_sym_link *pcStack_14;
  c1_sym_link cStack_10;
  
  pcStack_14 = &cStack_10;
  cStack_10.next = &cStack_10;
  cStack_10.position = (c1_u32)&cStack_10;
  cStack_10.type.type = (c1_type *)0x0;
  if (g_error_count == 0) {
    g_il_block_level = (scope->kind == 0xfb) - 1U & scope->kind;
    if (scope->kind != '\0') {
      il_emit_symbol(0xd,(c1_symbol *)0x0);
    }
    if ((scope->buckets != (c1_sym_link **)0x0) && (uVar6 = 0, scope->mask != 0xffffffff)) {
      do {
        pcStack_1c = scope->buckets[uVar6];
        while (pcStack_1c != (c1_sym_link *)0x0) {
          cVar4 = sym_not_written_to_il((c1_symbol *)&pcStack_1c[-1].position);
          if (cVar4 == '\0') {
            if (((g_il_block_level == '\0') && (g_pch_precomp_types == 0)) &&
               (cVar4 = sym_emission_must_wait((c1_symbol *)&pcStack_1c[-1].position), cVar4 != '\0'
               )) {
              dlist_insert_before(&pcStack_14,(int *)&pcStack_18,(int *)pcStack_14,
                                  (int *)&pcStack_1c);
              pcStack_1c = pcStack_1c->next;
            }
            else {
              il_emit_global_symbol((int *)pcStack_1c);
              pcStack_1c = pcStack_1c->next;
            }
          }
          else {
            pcStack_1c = pcStack_1c->next;
          }
        }
        uVar6 = uVar6 + 1;
        pcStack_1c = (c1_sym_link *)0x0;
      } while (uVar6 < scope->mask + 1);
    }
    bVar2 = false;
    pcVar1 = pcStack_14;
    while ((cStack_10.type.type != (c1_type *)0x0 && (!bVar2))) {
      pcVar5 = pcVar1->next;
      bVar2 = true;
      if (pcVar5 != pcVar1) {
        do {
          cVar4 = sym_emission_must_wait((c1_symbol *)&pcVar5->name[-1].macro);
          if (cVar4 == '\0') {
            bVar2 = false;
            il_emit_global_symbol((int *)pcVar5->name);
            pcVar1 = pcStack_14->next;
            if (pcVar5 == pcVar1) {
              pcVar5 = pcStack_14;
              pcVar3 = pcStack_14;
              if (cStack_10.type.type != (c1_type *)0x0) {
                pcStack_18 = pcVar1->next;
                *(c1_sym_link **)(pcVar1->position + 4) = pcStack_18;
                pcVar1->next->position = pcVar1->position;
                cStack_10.type.type = (c1_type *)((int)&cStack_10.type.type[-1].debug_index + 3);
                pcVar5 = pcStack_18;
                pcVar3 = pcStack_1c;
              }
            }
            else {
              pcVar1 = pcVar5->next;
              *(c1_sym_link **)(pcVar5->position + 4) = pcVar1;
              pcVar5->next->position = pcVar5->position;
              cStack_10.type.type = (c1_type *)((int)&cStack_10.type.type[-1].debug_index + 3);
              pcVar5 = pcVar1;
              pcVar3 = pcStack_1c;
            }
          }
          else {
            pcVar5 = pcVar5->next;
            pcVar3 = pcStack_1c;
          }
          pcStack_1c = pcVar3;
          pcVar1 = pcStack_14;
        } while (pcVar5 != pcStack_14);
      }
    }
  }
  return;
}

