void __cdecl token_io_release_record(int rec)

{
  if (rec != 0) {
    pch_relocate_slot((uint)(rec + 0xc));
    pch_relocate_slot(rec + 0x18);
    pch_relocate_slot(rec + 0x24);
    token_io_noop();
    token_io_noop();
    pch_relocate_token_chunks((void *)(rec + 0xc));
  }
  return;
}

