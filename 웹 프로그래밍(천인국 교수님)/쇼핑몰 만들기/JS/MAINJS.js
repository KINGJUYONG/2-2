/*  


    순천향대학교
    컴퓨터공학과
    20184102 신주용


*/

$(document).ready(function(){ // 페이지 로드와 동시에 실행됩니다.
  $('.mainpic').bxSlider( {
    mode: 'horizontal',// 가로 방향 수평 슬라이드
    speed: 1000,        // 이동 속도를 설정(낮을수록 빨라집니다.)
    pager: false,      // 현재 위치 페이징 표시 여부 설정
    moveSlides: 1,     // 슬라이드 이동시 개수
    slideMargin: 0,    // 슬라이드간의 간격
    auto: true,        // 자동 실행 여부
    autoHover: true,   // 마우스 호버시 정지 여부
    controls: true,    // 이전 다음 버튼 노출 여부
    responsive :false, // 자동 크기조절 사용 여부
    slideWidth: 906,   // 슬라이드의 크기
    adaptiveHeight :false, // 자동 높이 조절
    infiniteLoop :true, // 무한 반복(사진 이동)
    minSlides: 1, // 최소 슬라이드 노출 개수
    maxSlides: 10 // 최대 슬라이드 노출 개수
    });
});


function moveTop() {
  window.scrollTo({top:0, left:0, behavior:'smooth'}); // 위에서 0, 좌에서 0 위치로 smooth옵션을 사용하여 이동합니다.
}

function submitted() {
  alert("submitted"); // submitted 알림창을 띄웁니다.
}

var bgcolor = 0;
function nightmode() { // 야간모드에 관여하는 함수입니다.
  if (bgcolor == 0) { // 앞서 선언해준 bgcolor가 0일때
    document.body.style.backgroundColor = 'gray'; // 전체 배경의 색상을 gray로 설정하고,
    document.getElementById("credit").style.color = 'black'; // 푸터의 글자 색상을 black으로
    document.getElementById("credit").style.backgroundColor = 'dimgray'; // 푸터의 배경색을 dimgray로
    document.getElementById("hor").style.borderRight = '2px solid black'; // 푸터의 단락을 black으로 변경해줍니다.
    for(var i=0; i<7; i++) {
      document.getElementById("footermenu" + i).style.color = 'black'; // 이후 푸터 우측의 메뉴 색상을 for문을 이용하여 black으로 변경해줍니다.
    }
    bgcolor++;
  }
  else{
    document.body.style.backgroundColor = 'lightgray'; // bgcolor가 0이 아닐시 위와 동일하게 돌아갑니다.
    document.getElementById("credit").style.color = 'dimgray';
    document.getElementById("credit").style.backgroundColor = 'silver';
    document.getElementById("hor").style.borderRight = '2px solid dimgray';
    for(var i=0; i<7; i++) {
      document.getElementById("footermenu" + i).style.color = 'dimgray';
    }
    bgcolor--;
  }
}


function CloseModal(){ // 모달창을 닫는 버튼입니다.
  var CloseModal = document.querySelector(".container"); //.container을 CloseModal에 저장하고
  CloseModal.style.display ="none"; // .container을 보이지 않게 합니다.
}
function Checked() {
  var CloseModal = document.querySelector(".container"); // 위와 동일합니다.
  CloseModal.style.display ="none";
}