void * __fastcall arena_alloc(int arena,uint32_t size)

{
  c2_arena_page *page;
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint32_t rounded;
  c2_arena_page *pcVar4;
  c2_arena *arena_rec;
  char *result;
  
  rounded = size + 3 & 0xfffffffc;
  arena_rec = g_arenas + arena;
  if (0xff8 < rounded) {
    page = malloc(rounded + 8);
    if (page == (c2_arena_page *)0x0) {
      fatal_error(2);
    }
    pcVar4 = arena_rec->pages;
    if (pcVar4 == (c2_arena_page *)0x0) {
      arena_rec->pages = page;
      page->next = (c2_arena_page *)0x0;
    }
    else {
      page->next = pcVar4->next;
      pcVar4->next = page;
    }
    page->size = rounded;
    g_arenas[arena].remaining = 0;
    pcVar4 = page + 1;
    for (uVar2 = size + 3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      pcVar4->next = (c2_arena_page *)0x0;
      pcVar4 = (c2_arena_page *)&pcVar4->size;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)&pcVar4->next = 0;
      pcVar4 = (c2_arena_page *)((int)&pcVar4->next + 1);
    }
    return page + 1;
  }
  if ((int)g_arenas[arena].remaining < (int)rounded) {
    if (g_arena_free_pages == (c2_arena_page *)0x0) {
      page = malloc(0x1000);
      if (page == (c2_arena_page *)0x0) {
        fatal_error(2);
      }
      page->size = 0xff8;
    }
    else {
      page = g_arena_free_pages;
      g_arena_free_pages = g_arena_free_pages->next;
    }
    pcVar4 = arena_rec->pages;
    uVar2 = page->size;
    arena_rec->pages = page;
    page->next = pcVar4;
    g_arenas[arena].remaining = uVar2;
    g_arenas[arena].cursor = (char *)(page + 1);
    page = page + 1;
    for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      page->next = (c2_arena_page *)0x0;
      page = (c2_arena_page *)&page->size;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)&page->next = 0;
      page = (c2_arena_page *)((int)&page->next + 1);
    }
  }
  result = g_arenas[arena].cursor;
  g_arenas[arena].cursor = result + rounded;
  g_arenas[arena].remaining = g_arenas[arena].remaining - rounded;
  return result;
}

