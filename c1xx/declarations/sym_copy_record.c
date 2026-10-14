void __thiscall sym_copy_record(c1_symbol *dst,c1_symbol *sym,void *class_record,int arena)

{
  c1_sym_link *pcVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_sym_list *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  c1_symbol *pcVar9;
  uint *src;
  c1_symbol *pcVar10;
  
  uVar7 = g_symbol_size_table[sym->kind & 0x1f];
  pcVar9 = sym;
  pcVar10 = dst;
  for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    cVar2 = pcVar9->flags1;
    cVar3 = pcVar9->flags2;
    cVar4 = pcVar9->flags3;
    pcVar10->kind = pcVar9->kind;
    pcVar10->flags1 = cVar2;
    pcVar10->flags2 = cVar3;
    pcVar10->flags3 = cVar4;
    pcVar9 = (c1_symbol *)&pcVar9->flags4;
    pcVar10 = (c1_symbol *)&pcVar10->flags4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    pcVar10->kind = pcVar9->kind;
    pcVar9 = (c1_symbol *)&pcVar9->flags1;
    pcVar10 = (c1_symbol *)&pcVar10->flags1;
  }
  dst->kind = dst->kind & 0xdf;
  if ((sym->kind & 0x1f) == 4) {
    (dst->detail).ptr = class_record;
    iVar8 = 0x12;
    src = &((sym->detail).cls)->size;
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(uint *)class_record = *src;
      src = src + 1;
      class_record = (uint *)((int)class_record + 4);
    }
    if (arena == 0) {
      if (g_scope_pool_left < 0xc) {
        pool_reserve((c1xx_pool *)&g_scope_pool,0xc);
      }
      g_scope_pool_left = g_scope_pool_left - 0xc;
      pcVar5 = (c1_sym_list *)g_scope_pool;
      g_scope_pool = g_scope_pool + 0xc;
    }
    else {
      pcVar5 = arena_alloc(g_arenas + arena,0xc);
    }
    if (pcVar5 == (c1_sym_list *)0x0) {
      pcVar5 = (c1_sym_list *)0x0;
    }
    else {
      pcVar5->arena = arena;
      pcVar5->head = (c1_sym_link *)0x0;
      pcVar5->tail = (c1_sym_link *)0x0;
    }
    (dst->x28).members = pcVar5;
    pcVar1 = ((sym->x28).members)->head;
    pcVar5->tail = pcVar1;
    pcVar5->head = pcVar1;
  }
  return;
}

