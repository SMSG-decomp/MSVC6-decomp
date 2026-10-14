void __thiscall init_new_brace_level(c1_symbol *level,c1_symbol *rec,int arena)

{
  int iVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  c1_symbol *pcVar8;
  c1_symbol *pcVar9;
  
  uVar7 = g_symbol_size_table[rec->kind & 0x1f];
  pcVar8 = rec;
  pcVar9 = level;
  for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    cVar2 = pcVar8->flags1;
    cVar3 = pcVar8->flags2;
    cVar4 = pcVar8->flags3;
    pcVar9->kind = pcVar8->kind;
    pcVar9->flags1 = cVar2;
    pcVar9->flags2 = cVar3;
    pcVar9->flags3 = cVar4;
    pcVar8 = (c1_symbol *)&pcVar8->flags4;
    pcVar9 = (c1_symbol *)&pcVar9->flags4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    pcVar9->kind = pcVar8->kind;
    pcVar8 = (c1_symbol *)&pcVar8->flags1;
    pcVar9 = (c1_symbol *)&pcVar9->flags1;
  }
  level->kind = level->kind & 0xdf;
  if ((rec->kind & 0x1f) == 4) {
    if (arena == 0) {
      if (g_scope_pool.left < 0xc) {
        pool_reserve(&g_scope_pool,0xc);
      }
      g_scope_pool.left = g_scope_pool.left - 0xc;
      piVar5 = (int *)g_scope_pool.cur;
      g_scope_pool.cur = g_scope_pool.cur + 0xc;
    }
    else {
      piVar5 = arena_alloc(g_arenas + arena,0xc);
    }
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      *piVar5 = arena;
      piVar5[1] = 0;
      piVar5[2] = 0;
    }
    level->tag_members = piVar5;
    iVar1 = *(int *)((int)rec->tag_members + 4);
    piVar5[2] = iVar1;
    piVar5[1] = iVar1;
  }
  return;
}

