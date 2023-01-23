#!/bin/sh

test_description='git-psuh test

This test runs git-psuh and makes sure it does not crash.'

. ./test-lib.sh

test_expect_success 'runs correctly with no args and good output' '
    git psuh > actual && grep kostya actual
'

test_done   