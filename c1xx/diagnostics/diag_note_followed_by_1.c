void __fastcall diag_note_followed_by_1(c1_conversion *conv)

{
  diag_note(conv->note);
  diag_note(0x1838);
  diag_note_conversion_record(conv->first);
  return;
}

