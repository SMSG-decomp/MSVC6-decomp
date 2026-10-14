c2_block * __fastcall cfg_block_alloc(c2_cfg *cfg)

{
  c2_arena_page *pcVar1;
  c2_arena_page *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  c2_block *pcVar7;
  c2_block *pcVar8;
  c2_arena *arena;
  
  pcVar7 = cfg->free_blocks;
  if (pcVar7 != (c2_block *)0x0) {
    cfg->free_blocks = pcVar7->next;
    uVar4 = cfg->block_size;
    pcVar8 = pcVar7;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      pcVar8->next = (c2_block *)0x0;
      pcVar8 = (c2_block *)&pcVar8->prev;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)&pcVar8->next = 0;
      pcVar8 = (c2_block *)((int)&pcVar8->next + 1);
    }
    return pcVar7;
  }
  iVar5 = cfg->arena;
  uVar4 = cfg->block_size + 3;
  uVar6 = uVar4 & 0xfffffffc;
  arena = g_arenas + iVar5;
  if (0xff8 < uVar6) {
    pcVar2 = malloc(uVar6 + 8);
    if (pcVar2 == (c2_arena_page *)0x0) {
      fatal_error(2);
    }
    pcVar1 = arena->pages;
    if (pcVar1 == (c2_arena_page *)0x0) {
      arena->pages = pcVar2;
      pcVar2->next = (c2_arena_page *)0x0;
    }
    else {
      pcVar2->next = pcVar1->next;
      pcVar1->next = pcVar2;
    }
    pcVar2->size = uVar6;
    g_arenas[iVar5].remaining = 0;
    pcVar7 = (c2_block *)(pcVar2 + 1);
    for (uVar4 = uVar4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      pcVar7->next = (c2_block *)0x0;
      pcVar7 = (c2_block *)&pcVar7->prev;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)&pcVar7->next = 0;
      pcVar7 = (c2_block *)((int)&pcVar7->next + 1);
    }
    return (c2_block *)(pcVar2 + 1);
  }
  if ((int)g_arenas[iVar5].remaining < (int)uVar6) {
    if (g_arena_free_pages == (c2_arena_page *)0x0) {
      pcVar2 = malloc(0x1000);
      if (pcVar2 == (c2_arena_page *)0x0) {
        fatal_error(2);
      }
      pcVar2->size = 0xff8;
    }
    else {
      pcVar2 = g_arena_free_pages;
      g_arena_free_pages = g_arena_free_pages->next;
    }
    pcVar1 = arena->pages;
    uVar4 = pcVar2->size;
    arena->pages = pcVar2;
    pcVar2->next = pcVar1;
    g_arenas[iVar5].remaining = uVar4;
    g_arenas[iVar5].cursor = (char *)(pcVar2 + 1);
    pcVar2 = pcVar2 + 1;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar2->next = (c2_arena_page *)0x0;
      pcVar2 = (c2_arena_page *)&pcVar2->size;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)&pcVar2->next = 0;
      pcVar2 = (c2_arena_page *)((int)&pcVar2->next + 1);
    }
  }
  pcVar7 = (c2_block *)g_arenas[iVar5].cursor;
  g_arenas[iVar5].cursor = (char *)((int)&pcVar7->next + uVar6);
  g_arenas[iVar5].remaining = g_arenas[iVar5].remaining - uVar6;
  return pcVar7;
}

