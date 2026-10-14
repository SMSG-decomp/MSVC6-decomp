int __cdecl lex_scan_identifier(byte first)

{
  byte bVar1;
  uchar *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *start;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  fe_name *name_rec;
  fe_name *prev;
  fe_name *bucket;
  uchar *new_rec;
  
  uVar3 = (uint)first;
  uVar5 = 0;
  start = g_input_ptr + -1;
  bVar1 = g_char_flags[uVar3];
  while ((bVar1 & 3) != 0) {
    uVar5 = uVar3 + (uVar5 >> 4) + uVar5 * 4;
    first = *g_input_ptr;
    uVar3 = (uint)first;
    g_input_ptr = g_input_ptr + 1;
    bVar1 = g_char_flags[uVar3];
  }
  if ((g_char_class[first] == '\0') || ((first == 4 && (0 < g_macro_expansion_depth)))) {
    uVar5 = lex_scan_identifier_slow(start,uVar5,first);
    return uVar5;
  }
  g_input_ptr = g_input_ptr + -1;
  uVar3 = (int)g_input_ptr - (int)start;
  if (0x7ff < (int)uVar3) {
    diag_fatal_simple(0x40);
  }
  bucket = (fe_name *)(g_name_hash + (uVar5 & 0x7ff));
  uVar5 = uVar5 >> 0x10 ^ uVar5 & 0xffff;
  prev = bucket;
  name_rec = bucket->next;
  do {
    if (name_rec == (fe_name *)0x0) {
      if (g_name_pool_left < 0x10) {
        pool_reserve((c1xx_pool *)&g_name_pool,0x10);
      }
      new_rec = g_name_pool;
      g_name_pool_left = g_name_pool_left - 0x10;
      puVar2 = g_name_pool + 0x10;
      *(fe_name **)g_name_pool = bucket->next;
      g_name_pool = puVar2;
      bucket->next = (fe_name *)new_rec;
      pbVar6 = g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + (uVar3 + 4 & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(byte **)(new_rec + 4) = pbVar6;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pbVar6 = *(undefined4 *)start;
        start = start + 4;
        pbVar6 = pbVar6 + 4;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pbVar6 = *start;
        start = start + 1;
        pbVar6 = pbVar6 + 1;
      }
      *(undefined1 *)(*(int *)(new_rec + 4) + uVar3) = 0;
      g_last_name = (fe_name *)new_rec;
      *(uint *)(new_rec + 8) = (*(uint *)(new_rec + 8) ^ uVar5) & 0xffff ^ *(uint *)(new_rec + 8);
      return 0;
    }
    if (((name_rec->flags & 0xffff) == uVar5) && (name_rec->text[uVar3] == 0)) {
      bVar8 = true;
      uVar4 = uVar3;
      pbVar6 = start;
      pbVar7 = (byte *)name_rec->text;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar8 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        prev->next = name_rec->next;
        name_rec->next = bucket->next;
        bucket->next = name_rec;
        g_last_name = name_rec;
        return 0;
      }
    }
    prev = name_rec;
    name_rec = name_rec->next;
  } while( true );
}

