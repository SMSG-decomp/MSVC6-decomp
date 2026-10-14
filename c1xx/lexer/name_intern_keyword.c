void __cdecl name_intern_keyword(byte *text)

{
  byte bVar1;
  byte *pbVar2;
  uchar *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  fe_name *rec;
  fe_name *prev_link;
  fe_name *bucket;
  uchar *new_rec;
  
  pbVar8 = text;
  pbVar4 = (byte *)0x0;
  bVar1 = *text;
  pbVar2 = text;
  while (pbVar2 = pbVar2 + 1, bVar1 != 0) {
    text = (byte *)(uint)bVar1;
    pbVar4 = text + ((uint)pbVar4 >> 4) + (int)pbVar4 * 4;
    bVar1 = *pbVar2;
  }
  pbVar5 = pbVar2 + (-1 - (int)pbVar8);
  bucket = (fe_name *)(g_name_hash + ((uint)pbVar4 & 0x7ff));
  uVar7 = (uint)pbVar4 >> 0x10 ^ (uint)pbVar4 & 0xffff;
  prev_link = bucket;
  rec = bucket->next;
  do {
    if (rec == (fe_name *)0x0) {
      if (g_name_pool_left < 0x14) {
        pool_reserve((c1xx_pool *)&g_name_pool,0x14);
      }
      new_rec = g_name_pool;
      g_name_pool_left = g_name_pool_left - 0x14;
      puVar3 = g_name_pool + 0x14;
      *(fe_name **)g_name_pool = bucket->next;
      g_name_pool = puVar3;
      bucket->next = (fe_name *)new_rec;
      pbVar4 = g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + ((uint)(pbVar2 + (3 - (int)pbVar8)) & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(byte **)(new_rec + 4) = pbVar4;
      for (uVar6 = (uint)pbVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pbVar4 = *(undefined4 *)pbVar8;
        pbVar8 = pbVar8 + 4;
        pbVar4 = pbVar4 + 4;
      }
      for (uVar6 = (uint)pbVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pbVar4 = *pbVar8;
        pbVar8 = pbVar8 + 1;
        pbVar4 = pbVar4 + 1;
      }
      pbVar5[*(int *)(new_rec + 4)] = 0;
      g_last_name = (fe_name *)new_rec;
      *(uint *)(new_rec + 8) = (*(uint *)(new_rec + 8) ^ uVar7) & 0xffff ^ *(uint *)(new_rec + 8);
      return;
    }
    if (((rec->flags & 0xffff) == uVar7) && (rec->text[(int)pbVar5] == 0)) {
      bVar11 = true;
      pbVar4 = pbVar5;
      pbVar9 = pbVar8;
      pbVar10 = (byte *)rec->text;
      do {
        if (pbVar4 == (byte *)0x0) break;
        pbVar4 = pbVar4 + -1;
        bVar11 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar11);
      if (bVar11) {
        prev_link->next = rec->next;
        rec->next = bucket->next;
        bucket->next = rec;
        g_last_name = rec;
        return;
      }
    }
    prev_link = rec;
    rec = rec->next;
  } while( true );
}

