void __fastcall diag_note_conversion_call(c1_conversion *conv)

{
  diag_note_conversion_record(conv->first);
  diag_note(0x1838);
  diag_note(0x17ea,(conv->via).function);
  diag_note(0x1838);
  diag_note_conversion_record(conv->second);
  return;
}

