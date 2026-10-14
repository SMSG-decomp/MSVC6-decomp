void __fastcall arena_release_pages(c2_arena *arena)

{
  c2_arena_page *pcVar1;
  c2_arena_page *pcVar2;
  c2_arena_page *_Memory;
  c2_arena_page *pcVar3;
  c2_arena_page *pcVar4;
  
  pcVar1 = arena->pages;
  pcVar3 = (c2_arena_page *)0x0;
  _Memory = pcVar1;
  if (pcVar1 != (c2_arena_page *)0x0) {
    do {
      pcVar2 = _Memory->next;
      pcVar4 = _Memory;
      if (0xff8 < _Memory->size) {
        if (pcVar3 != (c2_arena_page *)0x0) {
          pcVar3->next = pcVar2;
        }
        free(_Memory);
        pcVar4 = pcVar3;
      }
      _Memory = pcVar2;
      pcVar3 = pcVar4;
    } while (pcVar2 != (c2_arena_page *)0x0);
    if (pcVar4 != (c2_arena_page *)0x0) {
      pcVar4->next = g_arena_free_pages;
      g_arena_free_pages = pcVar1;
    }
  }
  return;
}

