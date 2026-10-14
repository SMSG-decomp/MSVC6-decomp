void name_intern_keyword_fragment(fe_name *eax,int *edi,uint esi)

{
  uchar *puVar1;
  uchar *puVar2;
  fe_name *pfVar3;
  uint uVar4;
  uint unaff_EBP;
  c1_u8 *pcVar5;
  c1_u8 *pcVar6;
  bool bVar7;
  c1_u8 *in_stack_00000010;
  uint in_stack_00000014;
  int *in_stack_0000001c;
  
  do {
    do {
      pfVar3 = eax;
      eax = pfVar3->next;
      if (eax == (fe_name *)0x0) {
        if (g_name_pool_left < 0x14) {
          pool_reserve((c1xx_pool *)&g_name_pool,0x14);
        }
        puVar1 = g_name_pool;
        g_name_pool_left = g_name_pool_left - 0x14;
        puVar2 = g_name_pool + 0x14;
        *(int *)g_name_pool = *edi;
        g_name_pool = puVar2;
        *edi = (int)puVar1;
        pcVar5 = g_arenas[0].cur;
        g_arenas[0].cur = g_arenas[0].cur + (esi + 4 & 0xfffffffc);
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        *(c1_u8 **)(puVar1 + 4) = pcVar5;
        for (uVar4 = esi >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar5 = *(undefined4 *)in_stack_00000010;
          in_stack_00000010 = in_stack_00000010 + 4;
          pcVar5 = pcVar5 + 4;
        }
        for (uVar4 = esi & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar5 = *in_stack_00000010;
          in_stack_00000010 = in_stack_00000010 + 1;
          pcVar5 = pcVar5 + 1;
        }
        *(undefined1 *)(in_stack_00000014 + *(int *)(puVar1 + 4)) = 0;
        g_last_name = (fe_name *)puVar1;
        *(uint *)(puVar1 + 8) = (*(uint *)(puVar1 + 8) ^ unaff_EBP) & 0xffff ^ *(uint *)(puVar1 + 8)
        ;
        return;
      }
    } while (((eax->flags & 0xffff) != unaff_EBP) || (eax->text[esi] != '\0'));
    bVar7 = true;
    pcVar5 = in_stack_00000010;
    pcVar6 = (c1_u8 *)eax->text;
    do {
      if (esi == 0) break;
      esi = esi - 1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    esi = in_stack_00000014;
    edi = in_stack_0000001c;
    if (bVar7) {
      pfVar3->next = eax->next;
      eax->next = (fe_name *)*in_stack_0000001c;
      *in_stack_0000001c = (int)eax;
      g_last_name = eax;
      return;
    }
  } while( true );
}

