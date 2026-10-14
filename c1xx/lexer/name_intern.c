void * __cdecl name_intern(char *s)

{
  byte bVar1;
  byte *pbVar2;
  uchar *puVar3;
  char *pcVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  c1_u8 *pcVar9;
  c1_u8 *pcVar10;
  char *pcVar11;
  bool bVar12;
  fe_name *name_rec;
  fe_name *prev;
  fe_name *name_rec_2;
  fe_name *bucket;
  uchar *new_rec;
  
  pcVar9 = (c1_u8 *)s;
  pcVar4 = (char *)0x0;
  bVar1 = *s;
  pbVar2 = (byte *)s;
  while (pbVar2 = pbVar2 + 1, bVar1 != 0) {
    s = (char *)(uint)bVar1;
    pcVar4 = s + ((uint)pcVar4 >> 4) + (int)pcVar4 * 4;
    bVar1 = *pbVar2;
  }
  pbVar5 = pbVar2 + (-1 - (int)pcVar9);
  bucket = (fe_name *)(g_name_hash + ((uint)pcVar4 & 0x7ff));
  uVar8 = (uint)pcVar4 >> 0x10 ^ (uint)pcVar4 & 0xffff;
  prev = bucket;
  name_rec_2 = bucket->next;
  do {
    if (name_rec_2 == (fe_name *)0x0) {
      if (g_name_pool_left < 0x10) {
        pool_reserve((c1xx_pool *)&g_name_pool,0x10);
      }
      new_rec = g_name_pool;
      g_name_pool_left = g_name_pool_left - 0x10;
      puVar3 = g_name_pool + 0x10;
      *(fe_name **)g_name_pool = bucket->next;
      g_name_pool = puVar3;
      bucket->next = (fe_name *)new_rec;
      pcVar10 = g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + ((uint)(pbVar2 + (3 - (int)pcVar9)) & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(c1_u8 **)(new_rec + 4) = pcVar10;
      for (uVar6 = (uint)pbVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = (uint)pbVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
      pbVar5[*(int *)(new_rec + 4)] = 0;
      g_last_name = (fe_name *)new_rec;
      *(uint *)(new_rec + 8) = (*(uint *)(new_rec + 8) ^ uVar8) & 0xffff ^ *(uint *)(new_rec + 8);
      return g_last_name;
    }
    if (((name_rec_2->flags & 0xffff) == uVar8) && (name_rec_2->text[(int)pbVar5] == '\0')) {
      bVar12 = true;
      pbVar7 = pbVar5;
      pcVar4 = (char *)pcVar9;
      pcVar11 = name_rec_2->text;
      do {
        if (pbVar7 == (byte *)0x0) break;
        pbVar7 = pbVar7 + -1;
        bVar12 = *pcVar4 == *pcVar11;
        pcVar4 = pcVar4 + 1;
        pcVar11 = pcVar11 + 1;
      } while (bVar12);
      if (bVar12) {
        prev->next = name_rec_2->next;
        name_rec_2->next = bucket->next;
        bucket->next = name_rec_2;
        g_last_name = name_rec_2;
        return name_rec_2;
      }
    }
    prev = name_rec_2;
    name_rec_2 = name_rec_2->next;
  } while( true );
}

