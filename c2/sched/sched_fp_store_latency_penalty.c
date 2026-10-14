int __fastcall sched_fp_store_latency_penalty(void *edge)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)((int)edge + 8) + 0x1c) + 4);
  if ((((iVar1 != 0x5f) &&
       (iVar2 = *(int *)(*(int *)(*(int *)((int)edge + 0xc) + 0x1c) + 4), iVar2 != 0x5f)) &&
      ((iVar2 == 0x62 || (iVar2 == 99)))) &&
     ((((iVar1 == 0x45 || (iVar1 == 0x47)) || (iVar1 == 0x46)) || (iVar1 == 0x60)))) {
    return 1;
  }
  return 0;
}

