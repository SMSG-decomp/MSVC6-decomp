void __thiscall hash_scope_emit_il(c1_scope_object *hash_scope)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  c1_u8 cVar4;
  int *piVar5;
  uint uVar6;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int iStack_10;
  int *piStack_c;
  int *piStack_8;
  int iStack_4;
  
  piStack_14 = &iStack_10;
  piStack_c = &iStack_10;
  piStack_8 = &iStack_10;
  iStack_4 = 0;
  if (g_error_count == 0) {
    g_il_block_level = hash_scope->level;
    if (hash_scope != g_current_scope->file_scope) {
      il_emit_symbol(0xd,(c1_symbol *)0x0);
    }
    if (((hash_scope->entries).buckets != (void **)0x0) &&
       (uVar6 = 0, hash_scope->mask != 0xffffffff)) {
      do {
        piStack_1c = (hash_scope->entries).buckets[uVar6];
        while (piStack_1c != (int *)0x0) {
          if (((g_il_block_level == '\0') && (g_pch_precomp_types == '\0')) &&
             (cVar4 = scope_symbol_emits_late((c1_symbol *)(piStack_1c + -2)), cVar4 != '\0')) {
            dlist_insert_before(&piStack_14,(int *)&piStack_18,piStack_14,(int *)&piStack_1c);
            piStack_1c = (int *)piStack_1c[1];
          }
          else {
            il_emit_global_symbol(piStack_1c);
            piStack_1c = (int *)piStack_1c[1];
          }
        }
        uVar6 = uVar6 + 1;
        piStack_1c = (int *)0x0;
      } while (uVar6 < hash_scope->mask + 1);
    }
    bVar2 = false;
    piVar1 = piStack_14;
    while ((iStack_4 != 0 && (!bVar2))) {
      piVar5 = (int *)piVar1[1];
      bVar2 = true;
      if (piVar5 != piVar1) {
        do {
          cVar4 = scope_symbol_emits_late((c1_symbol *)(*piVar5 + -8));
          if (cVar4 == '\0') {
            bVar2 = false;
            il_emit_global_symbol((int *)*piVar5);
            piVar1 = (int *)piStack_14[1];
            if (piVar5 == piVar1) {
              piVar5 = piStack_14;
              piVar3 = piStack_14;
              if (iStack_4 != 0) {
                piStack_18 = (int *)piVar1[1];
                *(int **)(piVar1[2] + 4) = piStack_18;
                *(int *)(piVar1[1] + 8) = piVar1[2];
                iStack_4 = iStack_4 + -1;
                piVar5 = piStack_18;
                piVar3 = piStack_1c;
                bVar2 = false;
              }
            }
            else {
              piVar1 = (int *)piVar5[1];
              *(int **)(piVar5[2] + 4) = piVar1;
              *(int *)(piVar5[1] + 8) = piVar5[2];
              iStack_4 = iStack_4 + -1;
              piVar5 = piVar1;
              piVar3 = piStack_1c;
            }
          }
          else {
            piVar5 = (int *)piVar5[1];
            piVar3 = piStack_1c;
          }
          piStack_1c = piVar3;
          piVar1 = piStack_14;
        } while (piVar5 != piStack_14);
      }
    }
  }
  return;
}

