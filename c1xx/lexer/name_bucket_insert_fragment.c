uint __cdecl
name_bucket_insert_fragment
          (fe_name *entry,uint hash16,uint len,fe_name **bucket,uint hash16_cell,uint marker,
          fe_name **bucket_cell)

{
  uchar *puVar1;
  fe_name *pfVar2;
  uint uVar3;
  char *pcVar4;
  c1_u8 *pcVar5;
  char *pcVar6;
  c1_u8 *pcVar7;
  bool bVar8;
  uchar *new_rec;
  
  do {
    do {
      pfVar2 = entry;
      entry = pfVar2->next;
      if (entry == (fe_name *)0x0) {
        if (g_name_pool_left < 0x10) {
          pool_reserve((c1xx_pool *)&g_name_pool,0x10);
        }
        new_rec = g_name_pool;
        g_name_pool_left = g_name_pool_left - 0x10;
        puVar1 = g_name_pool + 0x10;
        *(fe_name **)g_name_pool = *bucket;
        g_name_pool = puVar1;
        *bucket = (fe_name *)new_rec;
        pcVar7 = g_arenas[0].cur;
        g_arenas[0].cur = g_arenas[0].cur + (len + 4 & 0xfffffffc);
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        *(c1_u8 **)(new_rec + 4) = pcVar7;
        pcVar5 = &stack0x0000001c;
        for (uVar3 = len >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar3 = len & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pcVar7 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
        }
        *(undefined1 *)(*(int *)(new_rec + 4) + len) = 0;
        g_last_name = (fe_name *)new_rec;
        *(uint *)(new_rec + 8) =
             (*(uint *)(new_rec + 8) ^ hash16_cell) & 0xffff ^ *(uint *)(new_rec + 8);
        goto LAB_1040ac9b;
      }
    } while (((entry->flags & 0xffff) != hash16) || (entry->text[len] != '\0'));
    bVar8 = true;
    uVar3 = len;
    pcVar4 = &stack0x0000001c;
    pcVar6 = entry->text;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar8 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    hash16 = hash16_cell;
    bucket = bucket_cell;
  } while (!bVar8);
  pfVar2->next = entry->next;
  entry->next = *bucket_cell;
  *bucket_cell = entry;
  g_last_name = entry;
LAB_1040ac9b:
  return (uint)((marker & 0xff) == len);
}

