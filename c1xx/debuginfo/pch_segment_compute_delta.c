void __fastcall pch_segment_compute_delta(int pch_stream_reader)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(pch_stream_reader + 0x28) - *(int *)(pch_stream_reader + 0x18);
  iVar2 = *(int *)(pch_stream_reader + 0x18) + *(int *)(pch_stream_reader + 0x1c);
  *(int *)(pch_stream_reader + 0x44) = iVar2;
  *(int *)(pch_stream_reader + 0x40) = iVar1;
  *(int *)(pch_stream_reader + 0x48) = iVar2 + iVar1;
  return;
}

