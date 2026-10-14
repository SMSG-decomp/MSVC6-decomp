void __fastcall diag_note_overload_resolved(c1_conversion *conv)

{
  diag_note(0x17e6,conv->overload_set,(conv->via).function);
  diag_note(0x1838);
  diag_note_conversion_record(conv->first);
  return;
}

