void __fastcall build_alias_conflict_lists(c2_bitset *classes,uint32_t max_cls,uint32_t nbase_cls)

{
  c2_alias_conflict *pcVar1;
  uint n;
  c2_alias_conflict **ppcVar2;
  uint32_t uVar3;
  c2_alias_conflict *pcVar4;
  uint n_00;
  
  g_alias_conflicts = arena_alloc(1,max_cls * 4 + 4);
  n_00 = 1;
  if (max_cls != 0) {
    do {
      uVar3 = bitset_test(classes,n_00);
      if ((uVar3 != 0) &&
         ((nbase_cls <= n_00 || (g_alias_class_symbol_sets[n_00] != (c2_bitvec *)0x0)))) {
        pcVar4 = arena_alloc(1,8);
        ppcVar2 = g_alias_conflicts;
        pcVar4->cls = n_00;
        pcVar1 = ppcVar2[n_00];
        ppcVar2[n_00] = pcVar4;
        pcVar4->next = pcVar1;
        n = n_00;
        while (n = n + 1, n <= max_cls) {
          if ((((nbase_cls <= n) || (g_alias_class_symbol_sets[n] != (c2_bitvec *)0x0)) &&
              ((g_alias_symbol_class_count <= n_00 ||
               (((n_00 < g_alias_class_skip_index || (g_alias_symbol_class_count <= n)) ||
                (n < g_alias_class_skip_index)))))) &&
             ((uVar3 = bitset_test(classes,n), uVar3 != 0 &&
              (uVar3 = alias_classes_intersect(n_00,n), uVar3 != 0)))) {
            pcVar4 = arena_alloc(1,8);
            ppcVar2 = g_alias_conflicts;
            pcVar4->cls = n;
            pcVar1 = ppcVar2[n_00];
            ppcVar2[n_00] = pcVar4;
            pcVar4->next = pcVar1;
            pcVar4 = arena_alloc(1,8);
            ppcVar2 = g_alias_conflicts;
            pcVar4->cls = n_00;
            pcVar1 = ppcVar2[n];
            ppcVar2[n] = pcVar4;
            pcVar4->next = pcVar1;
          }
        }
      }
      n_00 = n_00 + 1;
    } while (n_00 <= max_cls);
  }
  return;
}

